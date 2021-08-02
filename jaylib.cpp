#include "jaylib.h"
#include "utils.h"

void Jaylib::drawBand(uint8_t x, uint8_t y, const uint8_t * sprite, uint8_t cols, uint8_t color) {
    uint16_t s;
    uint16_t p = (y >> 3) * WIDTH + cols + x - 1;

    for(; cols --; p --) {
        s = pgm_read_byte(sprite + cols) << (y & 0x7);

        if(color) {
            sBuffer[p] |= s;
            sBuffer[p + WIDTH] |= s >> 8;
        } else {
            sBuffer[p] &=~ s;
            sBuffer[p + WIDTH] &= ~s >> 8;
        }
    }
}

void Jaylib::smallPrint(uint8_t x, uint8_t y, const uint8_t * str, uint8_t color) {
    char c;
    for(;c = *str ++;) {
        c -= 32;
        drawBand(x, y, PRINTABLE_CHARS + 3 * c, 3, color);
        x += 4;
    }
}

void Jaylib::largePrint(uint8_t x, uint8_t y, const uint8_t * str, uint8_t kern, uint8_t color) {
    char c;
    for(;c = *str ++;) {
        c &= 0x1F; // Lucky that SPACE % 32 == 0
        drawBand(x, y, PRINTABLE_CHARS_LARGE + 5 * c, 5, color);
        x += 5 + kern;
    }
}

/*
void Jaylib::drawFastVLine(uint8_t x, uint8_t y, uint8_t h, uint8_t color) {
    uint8_t i;
    for(i = h; i --;)
        drawPixel(x, y + i, color);
}
*/

void Jaylib::drawFastVLine(uint8_t x, uint8_t y, uint8_t h, uint8_t color) {
    // Crop the line if it's off the bottom edge.
    if(y + h > HEIGHT)
        h = HEIGHT - y;

    // The screen is arranged as 8-pixel vertical stripes laid horizontally.
    uint8_t *pBuf = sBuffer + (y / (HEIGHT / 8)) * WIDTH + x;

    uint8_t mask;

    color = color ? 0xff : 0;

    // Handle the beginning of the line where the first
    // segment might only partially fill up an 8-pixel block.
    uint8_t shift = y & 0x7;
    if(h <= 8 - shift) {
        mask = ~(0xFF << (h & 0x7)) << shift;
        if(color) *pBuf |= mask;
        else *pBuf &= ~mask;
        return;
    }

    // Line must reach the end of the block;
    mask = 0xFF << shift;
    if(color) *pBuf |= mask;
    else *pBuf &= ~mask;
    h -= 8 - shift;

    // Draw all complete 8-pixel segments.
    for(;h > 8; h-= 8) {
        pBuf += WIDTH;
        *pBuf = color;
    }

    // Handle the case where a partial segment is left over.
    if(h) {
        pBuf += WIDTH;
        mask = 0xff << h;
        if(color) *pBuf |= ~mask;
        else *pBuf &= mask;
    }
}

void Jaylib::drawFastHLine(uint8_t x, uint8_t y, uint8_t w, uint8_t color) {
    uint8_t i;
    for(i = w; i --;)
        drawPixel(x + i, y, color);
}

void Jaylib::display() {
    counter ++;
    Arduboy2Base::display();
}
