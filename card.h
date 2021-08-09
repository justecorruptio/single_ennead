#pragma once

#include "jaylib.h"

typedef union {
    uint8_t v;
    struct {
        uint8_t y: 4;
        uint8_t x: 4;
    };
} Eyes;

typedef union {
    uint16_t v;
    struct {
        uint16_t s: 4;
        uint16_t e: 4;
        uint16_t n: 4;
        uint16_t w: 4;
    };

    uint8_t dir(uint8_t v) {
        switch(v) {
            case 0: return w;
            case 1: return n;
            case 2: return e;
            case 3: return s;
        }
    }
} Strength;

class Card {
    public:
    uint8_t sprite[8];
    uint8_t eyes;
    uint16_t _strength;
    char* _name;
    char* _flavor;

    void print(Jaylib &jay, uint8_t x, uint8_t y, uint8_t color, uint8_t draw_art=1);
    void printBack(Jaylib &jay, uint8_t x, uint8_t y, uint8_t color);

    Strength strength();
    char* name();
    char* flavor();
};
