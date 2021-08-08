#pragma once

#include <stdint.h>

typedef struct {
    int8_t x;
    int8_t y;
} Pos;

char * itoa(int16_t x, int base=10);
uint8_t strlen(const uint8_t* s);
uint8_t popcount(uint8_t n);
