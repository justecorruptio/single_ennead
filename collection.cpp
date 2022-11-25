#include "collection.h"

void Collection::init() {
    uint16_t magic = (EEPROM[17] << 8) | EEPROM[16];
    if (magic != COLLECTION_MAGIC) {
        EEPROM[17] = (COLLECTION_MAGIC >> 8) & 0xff;
        EEPROM[16] = (COLLECTION_MAGIC >> 0) & 0xff;
        for(int i = 0; i < 13; i ++) { // E[18] - E[30]
            EEPROM[i + 18] = 0x0;
        }
        EEPROM[18] = 0x1f;

        //money
        setMoney(0);

        //rules
        EEPROM[34] = 0;
        EEPROM[33] = 0;
        //setRule(RULE_PAYOUT_TRIPLE);
    }
}

uint8_t Collection::hasCard(uint8_t n) {
    n --;
    return (EEPROM[(n / 8) + 18] >> (n % 8)) & 0x1;
}

void Collection::addCard(uint8_t n) {
    n --;
    uint8_t v = EEPROM[(n / 8) + 18];
    v |= 1 << (n % 8);
    EEPROM[(n / 8) + 18] = v;
}

void Collection::deleteCard(uint8_t n) {
    n --;
    uint8_t v = EEPROM[(n / 8) + 18];
    v &= ~(1 << (n % 8));
    EEPROM[(n / 8) + 18] = v;
}

uint8_t Collection::numCollected() {
    uint8_t sum = 0;
    for(int i = 0; i < 13; i ++) { // E[18] - E[21]
        sum += popcount(EEPROM[i + 18]);
    }
    return sum;
}

uint16_t Collection::getMoney() {
    return (EEPROM[32] << 8) | EEPROM[31];
}

void Collection::setMoney(uint16_t money) {
    if (money > 60000) money = 60000;
    EEPROM[32] = (money >> 8) & 0xff;
    EEPROM[31] = (money >> 0) & 0xff;
}

Rules Collection::getRules() {
    return {(EEPROM[34] << 8) | EEPROM[33]};
}

void Collection::setRule(uint8_t rule) {
    uint8_t offset = (rule >> 4) * 2;
    Rules rules = getRules();
    rules.v = (rules.v & ~(3 << offset)) | ((rule & 3) << offset);
    EEPROM[34] = (rules.v >> 8) & 0xff;
    EEPROM[33] = (rules.v >> 0) & 0xff;
}

uint8_t Collection::checkRule(uint8_t rule) {
    uint8_t offset = (rule >> 4) * 2;
    Rules rules = getRules();
    return ((rules.v >> offset) & 3 ) == (rule & 3);
}

void Collection::spreadRule() {
    uint16_t money = getMoney();
    if(money < 500) return;
    money -= 500;
    setMoney(money);
    uint8_t rule;
    do {
        rule = pgm_read_byte(RULES_LIST + random(NUM_RULES));
    } while(checkRule(rule));
    setRule(rule);
}

void Collection::resetPicker() {
    cursor.x = cursor.y = 0;
    numCards = 0;
}

void Collection::moveCursor(int8_t x, int8_t y) {
    cursor.x = (cursor.x + x + 10) % 10;
    cursor.y = (cursor.y + y + 10) % 10;
}

void Collection::selectCard() {
    uint8_t pos = cursor.x * 10 + cursor.y;
    if (numCards == 5) return;
    if (!hasCard(pos + 1)) return;

    for(int i = 0; i < numCards; i++) {
        if (my_cards[i] == pos + 1) return;
    }
    my_cards[numCards] = pos + 1;
    numCards ++;
}

void Collection::deselectCard() {
    if(numCards) numCards--;
}

void Collection::selectAICards() {

    uint8_t nc = numCollected();
    if(nc == 100) { // killscreen
        for(int i = 0; i < 5; i++) {
            ai_cards[i] = 101;
        }
        return;
    }

    uint8_t min = (nc / 10) * 10 + 1;
    uint8_t max = (nc / 10) * 9 + 21;
    if (max > 100) max = 100;

    for(int i = 0; i < 5; i++) {
        uint8_t c;
        uint8_t found;
        do {
            c = random(min, max);
            found = 0;
            for(int j = 0; j < i; j++){
                if(ai_cards[j] == c) {
                    found = 1;
                    break;
                }
            }
        } while(found);
        ai_cards[i] = c;
    }
}

void Collection::setOutcome(int8_t _result) {
    result = _result;

    uint8_t nc = numCollected();
    if (result < 1)
        payout = 10;
    else {
        payout = Card(nc).cost() / 10;
        if(checkRule(RULE_PAYOUT_DOUBLE)) payout *= 2;
        else if(checkRule(RULE_PAYOUT_TRIPLE)) payout *= 3;
        else if(checkRule(RULE_PAYOUT_QUAD)) payout *= 4;

        if(payout < 20) payout = 20;
    }

    winCard = 0;
    loseCard = 0;
    bonus = 0;

    uint8_t c = 0;
    if(result == 1) {
        if (checkRule(RULE_WIN_RANDOM)) {
            c = ai_cards[random(5)];
        } else {
            for(int i = 0; i < 5; i++) {
                if(
                    c == 0 ||
                    (checkRule(RULE_WIN_LOWEST) && ai_cards[i] < c) ||
                    (checkRule(RULE_WIN_HIGHEST) && ai_cards[i] > c)
                ) c = ai_cards[i];
            }
        }
        winCard = c;

        if(hasCard(c)) {
            bonus = Card(c).cost() / 8;
        } else {
            addCard(c);
        }
    } else if (result == -1) {
        if (checkRule(RULE_WIN_RANDOM)) {
            c = my_cards[random(5)];
        } else {
            for(int i = 0; i < 5; i++) {
                if(
                    c == 0 ||
                    (checkRule(RULE_WIN_LOWEST) && my_cards[i] < c) ||
                    (checkRule(RULE_WIN_HIGHEST) && my_cards[i] > c)
                ) c = my_cards[i];
            }
        }
        loseCard = c;
        deleteCard(c);
    }

    uint16_t money = getMoney();
    money += payout + bonus;
    setMoney(money);
}

uint8_t Collection::canBuy() {
    uint8_t c = cursor.x * 10 + cursor.y + 1;
    return !hasCard(c) && getMoney() >= Card(c).cost();
}

void Collection::buy() {
    uint8_t c = cursor.x * 10 + cursor.y + 1;
    addCard(c);
    uint16_t money = getMoney();
    money -= Card(c).cost();
    setMoney(money);
}

void Collection::printMatrix(Jaylib &jay, int8_t x) {
    uint8_t c = (jay.counter / 4) % 4;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            uint8_t selected = 0;
            for(int k = 0; k < numCards; k++) {
                if (my_cards[k] == i * 10 + j + 1){
                    selected = 1;
                    break;
                }
            }
            uint8_t blink = cursor.x == i && cursor.y == j && c < 2;
            uint8_t has = hasCard(i * 10 + j + 1);
            jay.drawBand(
                x + i * 5 + !blink,
                j * 6 + 1 + !blink,
                GLYPH_COLLECTION_ICONS + has * 10 + selected * 10 + blink * 4,
                4 + blink * 2, 1
            );
        }
    }
}

void Collection::printMoney(Jaylib &jay) {
    jay.drawFastVLine(88, 0, 10, 1);
    jay.drawFastHLine(88, 9, 40, 1);
    jay.largePrint(90, 1, "$", 1, 1);
    jay.largePrint(98, 1, itoa(getMoney()), 1, 1);
}

void Collection::printInspect(Jaylib &jay) {
    printMatrix(jay, 0);
    printMoney(jay);
    uint8_t hovered = cursor.x * 10 + cursor.y + 1;
    jay.largePrint(73, 13, "#", 1, 1);
    jay.largePrint(73 + 6, 13, itoa(hovered), 1, 1);

    if(hasCard(hovered)) { // TODO
        Card(hovered).print(jay, 53, 1, 1);
        jay.largePrint(53, 23, Card(hovered).name(), 1, 1);
        jay.smallPrintWrapped(53, 33, 128 - 53, Card(hovered).flavor(), 1);
    } else {
        Card(hovered).printBack(jay, 53, 1, 0);
        jay.largePrint(53, 23, "????????", 1, 1);
        jay.largePrint(53, 33, "Worth $", 1, 1);
        jay.largePrint(95, 33, itoa(Card(hovered).cost()), 1, 1);
    }
}

void Collection::printPicker(Jaylib &jay) {
    printMatrix(jay, 24);
    uint8_t hovered = cursor.x * 10 + cursor.y + 1;
    if(hasCard(hovered)) {
        Card(hovered).print(jay, 77, 10, 1);
        jay.smallPrint(77, 33, Card(hovered).name(), 1);
    } else {
        Card(hovered).printBack(jay, 77, 10, 0);
    }
    jay.largePrint(77, 1, "#", 1, 1);
    jay.largePrint(77 + 6, 1, itoa(hovered), 1, 1);
}

void Collection::printSelection(Jaylib &jay) {
    for(int i = 0; i < numCards; i++) {
        if(my_cards[i]) {
            jay.drawFastHLine(1, i * 12, 18, 0);
            jay.drawFastVLine(19, i * 12, 20, 0);
            jay.drawFastVLine(0, i * 12, 20, 0);
            Card(my_cards[i]).print(jay, 1, i * 12 + 1, 1);
        }
    }
}

void Collection::printOutcome(Jaylib &jay) {
    jay.largePrint(1, 1, "Result:", 1, 1);
    jay.drawFastHLine(0, 10, 128, 1);
    if (result == 1) {
        jay.largePrint(48, 1, "Victory!", 1, 1);

        jay.largePrint(19, 25, "Card won:", 1, 1);
        Card(winCard).print(jay, 79, 12, 1);
        jay.largePrint(99, 25, "#", 1, 1);
        jay.largePrint(105, 25, itoa(winCard), 1, 1);
        jay.largePrint(19, 34, "  Payout: $", 1, 1);
        jay.largePrint(85, 34, itoa(payout), 1, 1);

        if(bonus) {
            jay.smallPrint(99, 12, "ALREADY\nOWNED", 1);
            jay.largePrint(1, 43, "Owned Bonus: $", 1, 1);
            jay.largePrint(85, 43, itoa(bonus), 1, 1);
        }
    } else if(result == -1) {
        jay.largePrint(48, 1, "Defeat!", 1, 1);

        jay.largePrint(13, 25, "Card lost:", 1, 1);
        Card(loseCard).print(jay, 79, 12, 1);
        jay.largePrint(99, 25, "#", 1, 1);
        jay.largePrint(105, 25, itoa(loseCard), 1, 1);
        jay.largePrint(19, 34, "  Payout: $", 1, 1);
        jay.largePrint(85, 34, itoa(payout), 1, 1);

    } else {
        jay.largePrint(48, 1, "Draw!", 1, 1);

        jay.largePrint(19, 34, "  Payout: $", 1, 1);
        jay.largePrint(85, 34, itoa(payout), 1, 1);
    }
}

void Collection::printRules(Jaylib &jay) {
    printMoney(jay);
    jay.largePrint(1, 1, "Active Rules", 1, 1);
    jay.drawFastHLine(0, 9, 128, 1);

    Rules rules = getRules();
    for(int i = 0; i < 6; i++){
        char * str = loadPStr(pgm_read_word(&RULE_STRINGS[i][(rules.v >> (i * 2)) & 3]));
        jay.largePrint(1, i * 9 + 11, str, 1);
    }

    for(int i = 0; i < 4; i++)
        jay.drawBand(98, i * 8 + 11, GLYPH_QR + i * 29, 29);
}
