#include "utils.h"

char itoa_buf[9] = "\0\0\0\0\0\0\0\0";
char * itoa(uint16_t x, int base) {
    uint8_t i = 7;
    do {
        char c = (x % base) + '0';
        if (c > '9'){
            c = c - '9' + 'A' - 1;
        }
        itoa_buf[i--] = c;
        x /= base;
    } while(x);

    // Must immediately use this.
    return itoa_buf + i + 1;
}

uint8_t strlen(const uint8_t* s) {
    uint8_t* t = s;
    while(*t) t++;
    return t - s;
}

uint8_t popcount(uint8_t n) {
    n = ((n & 0xaa) >> 1) + ((n & 0x55) >> 0);
    n = ((n & 0xcc) >> 2) + ((n & 0x33) >> 0);
    n = ((n & 0xf0) >> 4) + ((n & 0x0f) >> 0);
    return n;
};
