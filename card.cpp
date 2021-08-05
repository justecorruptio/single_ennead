#include "card.h"
#include "utils.h"
#include "glyphs.h"

Strength Card::strength() {
    return {pgm_read_word(&_strength)};
}

void Card::print(Jaylib &jay, uint8_t x, uint8_t y, uint8_t color, uint8_t draw_art) {
    for(int i = 0; i < 18; i++) {
        jay.drawFastVLine(x + i, y, 20, !color);
    }
    if(color) {
        jay.drawFastHLine(x, y, 3, 1);
        jay.drawFastHLine(x + 8, y, 9, 1);
        jay.drawFastHLine(x, y + 19, 17, 1);
        jay.drawPixel(x, y + 1, 1);
        jay.drawFastVLine(x, y + 9, 11, 1);
        jay.drawFastVLine(x + 17, y, 20, 1);
    }
    jay.drawPixel(x, y, 0);
    jay.drawPixel(x + 17, y, 0);
    jay.drawPixel(x, y + 19, 0);
    jay.drawPixel(x + 17, y + 19, 0);

    Strength s = strength();
    jay.smallPrint(x, y + 3, itoa(s.w, 16), color);
    jay.smallPrint(x + 4, y, itoa(s.n, 16), color);
    jay.smallPrint(x + 8, y + 3, itoa(s.e, 16), color);
    jay.smallPrint(x + 4, y + 6, itoa(s.s, 16), color);

    if(!draw_art) return;

    jay.drawBand(x + 8, y + 10, sprite, 8, color);

    Eyes e = {pgm_read_byte(&eyes)};
    int blink = (jay.counter >> 2) & 0xff;
    uint8_t blink1= (pgm_read_byte(sprite + 3)* 99 + pgm_read_byte(sprite + 5)) & 0xff;
    uint8_t blink2= ((blink1 * 51 + pgm_read_byte(sprite + 1)) * 77) & 0xff;
    if (blink != blink1 && blink != blink2) {
        jay.drawPixel(x + e.x + 8, y + e.y + 10, color);
        jay.drawPixel(x + e.x + 10, y + e.y + 10, color);
    }
}

void Card::printBack(Jaylib &jay, uint8_t x, uint8_t y, uint8_t color) {
    for(int i = 0; i < 18; i++) {
        jay.drawFastVLine(x + i, y, 20, !color);
    }
    jay.drawPixel(x, y, 0);
    jay.drawPixel(x + 17, y, 0);
    jay.drawPixel(x, y + 19, 0);
    jay.drawPixel(x + 17, y + 19, 0);
    jay.drawBand(x + 2, y + 2, GLYPH_CARD_LOGO, 14, color);
}
