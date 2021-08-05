#include "collection.h"

void Collection::moveCursor(int8_t x, int8_t y) {
    cursor.x = (cursor.x + x + 10) % 10;
    cursor.y = (cursor.y + y + 10) % 10;
}

void Collection::print(Jaylib &jay) {
    uint8_t c = (jay.counter / 4) % 4;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            uint8_t blink = cursor.x == i && cursor.y == j && c < 2;
            if (blink)
                jay.drawBand(i * 5 + 1, j * 6 + 1, GLYPH_COLLECTION_ICONS + 10 +4, 6, 1);
            else
                jay.drawBand(i * 5 + 2, j * 6 + 2, GLYPH_COLLECTION_ICONS + 10, 4, 1);
        }
    }
}
