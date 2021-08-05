#pragma once

#include "utils.h"
#include "jaylib.h"
#include "glyphs.h"

class Collection {

    public:
    Pos cursor;

    void moveCursor(int8_t x, int8_t y);

    void print(Jaylib &jay);
};
