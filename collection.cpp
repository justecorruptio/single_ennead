#include "collection.h"

void Collection::init() {
    uint16_t magic = (EEPROM[17] << 8) | EEPROM[16];
    if (magic != COLLECTION_MAGIC) {
        EEPROM[17] = (COLLECTION_MAGIC >> 8) & 0xff;
        EEPROM[16] = (COLLECTION_MAGIC >> 0) & 0xff;
        for(int i = 0; i < 13; i ++) { // E[18] - E[21]
            EEPROM[i + 18] = 0;
        }
        EEPROM[18] = 0xff;
    }
}

uint8_t Collection::hasCard(uint8_t n) {
    return (EEPROM[(n / 8) + 18] >> (n % 8)) & 0x1;
}

void Collection::moveCursor(int8_t x, int8_t y) {
    cursor.x = (cursor.x + x + 10) % 10;
    cursor.y = (cursor.y + y + 10) % 10;
}

void Collection::printMatrix(Jaylib &jay, int8_t x) {
    uint8_t c = (jay.counter / 4) % 4;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            uint8_t blink = cursor.x == i && cursor.y == j && c < 2;
            uint8_t has = hasCard(i * 10 + j);
            if (blink)
                jay.drawBand(x + i * 5 + 0, j * 6 + 1, GLYPH_COLLECTION_ICONS + has * 10 + 4, 6, 1);
            else
                jay.drawBand(x + i * 5 + 1, j * 6 + 2, GLYPH_COLLECTION_ICONS + has * 10, 4, 1);
        }
    }
}

void Collection::printInspect(Jaylib &jay) {
    printMatrix(jay, 0);
    uint8_t hovered = cursor.x * 10 + cursor.y + 1;
    CARDS[hovered].print(jay, 78, 1, 1);
    jay.largePrint(53, 1, "#", 1, 1);
    jay.largePrint(53 + 6, 1, itoa(hovered), 1, 1);
    jay.largePrint(53, 22, CARDS[hovered].name(), 1, 1);
    jay.smallPrintWrapped(53, 31, 128 - 53, CARDS[hovered].flavor(), 1);
}

void Collection::printPicker(Jaylib &jay) {
    printMatrix(jay, 20);
    uint8_t hovered = cursor.x * 10 + cursor.y + 1;
    CARDS[hovered].print(jay, 73, 10, 1);
    jay.largePrint(73, 1, "#", 1, 1);
    jay.largePrint(73 + 6, 1, itoa(hovered), 1, 1);
    jay.smallPrint(73, 33, CARDS[hovered].name(), 1);
}
