#pragma once

#include <stdint.h>

typedef struct {
    int8_t x;
    int8_t y;
} Pos;

char * itoa(int16_t x, int base=10);
