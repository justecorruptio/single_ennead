#pragma once

#include "utils.h"
#include "jaylib.h"
#include "glyphs.h"
#include "card_data.h"

#define COLLECTION_MAGIC 0xf49f

class Collection {

    public:
    Pos cursor;
    uint8_t cards[5];
    uint8_t numCards;

    void init();
    uint8_t hasCard(uint8_t n);
    uint8_t numCollected();

    uint16_t getMoney();
    uint16_t cost(uint8_t n);

    void resetPicker();
    void moveCursor(int8_t x, int8_t y);
    void selectCard();
    void deselectCard();

    void printInspect(Jaylib &jay);
    void printPicker(Jaylib &jay);
    void printMatrix(Jaylib &jay, int8_t x);

    void printSelection(Jaylib &jay);
};
