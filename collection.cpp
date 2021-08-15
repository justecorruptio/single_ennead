#include "collection.h"

void Collection::init() {
    uint16_t magic = (EEPROM[17] << 8) | EEPROM[16];
    if (magic != COLLECTION_MAGIC) {
        EEPROM[17] = (COLLECTION_MAGIC >> 8) & 0xff;
        EEPROM[16] = (COLLECTION_MAGIC >> 0) & 0xff;
        for(int i = 0; i < 13; i ++) { // E[18] - E[30]
            EEPROM[i + 18] = 0;
        }
        EEPROM[18] = 0xff;
        EEPROM[19] = 0x04;
        EEPROM[20] = 0xc1;
        EEPROM[21] = 0x23;

        //money
        setMoney(29358);

        //rules
        EEPROM[34] = 0;
        EEPROM[33] = 0;
        //setRule(RULE_PAYOUT_TRIPLE);
    }
}

uint8_t Collection::hasCard(uint8_t n) {
    return (EEPROM[(n / 8) + 18] >> (n % 8)) & 0x1;
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
    if (!hasCard(pos)) return;

    for(int i = 0; i < numCards; i++) {
        if (cards[i] == pos + 1) return;
    }
    cards[numCards] = pos + 1;
    numCards ++;
}

void Collection::deselectCard() {
    if(numCards) numCards--;
}

void Collection::printMatrix(Jaylib &jay, int8_t x) {
    uint8_t c = (jay.counter / 4) % 4;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            uint8_t selected = 0;
            for(int k = 0; k < numCards; k++) {
                if (cards[k] == i * 10 + j + 1){
                    selected = 1;
                    break;
                }
            }
            uint8_t blink = cursor.x == i && cursor.y == j && c < 2;
            uint8_t has = hasCard(i * 10 + j);
            jay.drawBand(
                x + i * 5 + !blink,
                j * 6 + 1 + !blink,
                GLYPH_COLLECTION_ICONS + has * 10 + selected * 10 + blink * 4,
                4 + blink * 2, 1
            );
        }
    }
}

void Collection::printInspect(Jaylib &jay) {
    printMatrix(jay, 0);
    uint8_t hovered = cursor.x * 10 + cursor.y + 1;
    jay.largePrint(73, 13, "#", 1, 1);
    jay.largePrint(73 + 6, 13, itoa(hovered), 1, 1);

    if(hasCard(hovered) || 1) { // TODO
        Card(hovered).print(jay, 53, 1, 1);
        jay.largePrint(53, 23, Card(hovered).name(), 1, 1);
        jay.smallPrintWrapped(53, 33, 128 - 53, Card(hovered).flavor(), 1);
    } else {
        Card(hovered).printBack(jay, 53, 1, 0);
        jay.largePrint(53, 23, "????????", 1, 1);
        jay.largePrint(53, 33, "Worth $", 1, 1);
        jay.largePrint(95, 33, itoa(Card(hovered).cost()), 1, 1);
    }

    jay.drawFastVLine(88, 0, 10, 1);
    jay.drawFastHLine(88, 9, 40, 1);
    jay.largePrint(90, 1, "$", 1, 1);
    jay.largePrint(98, 1, itoa(getMoney()), 1, 1);
}

void Collection::printPicker(Jaylib &jay) {
    printMatrix(jay, 24);
    uint8_t hovered = cursor.x * 10 + cursor.y + 1;
    Card(hovered).print(jay, 77, 10, 1);
    jay.largePrint(77, 1, "#", 1, 1);
    jay.largePrint(77 + 6, 1, itoa(hovered), 1, 1);
    jay.smallPrint(77, 33, Card(hovered).name(), 1);
}

void Collection::printSelection(Jaylib &jay) {
    for(int i = 0; i < numCards; i++) {
        if(cards[i]) {
            jay.drawFastHLine(1, i * 12, 18, 0);
            jay.drawFastVLine(19, i * 12, 20, 0);
            jay.drawFastVLine(0, i * 12, 20, 0);
            Card(cards[i]).print(jay, 1, i * 12 + 1, 1);
        }
    }
}
