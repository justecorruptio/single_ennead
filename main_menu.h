#pragma once

#include "jaylib.h"
#include "glyphs.h"

class MainMenu {
    public:
    uint8_t pan;
    uint8_t cursor;

    void print(Jaylib &jay, uint8_t numCollected);
    void cursorInc(int8_t step);

    void reset();
};
