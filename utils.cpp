#include "utils.h"

char itoa_buf[8] = "\0\0\0\0\0\0\0\0";
char * itoa(int16_t x, int base) {
    // buf is at least char[8];
    uint8_t i = 6;
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
