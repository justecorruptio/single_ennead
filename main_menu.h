#pragma once

#include "jaylib.h"
#include "glyphs.h"

class MainMenu {
    public:
    uint8_t pan;

    void print(Jaylib &jay);

    void reset();
};
