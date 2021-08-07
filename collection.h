#pragma once

#include "utils.h"
#include "jaylib.h"
#include "glyphs.h"
#include "card_data.h"

#define COLLECTION_MAGIC 0xf49d

class Collection {

    public:
    Pos cursor;
    uint8_t cards[5];
    uint8_t num_cards;

    void init();
    uint8_t hasCard(uint8_t n);

    void moveCursor(int8_t x, int8_t y);
    void selectCard();
    void deselectCard();

    void printInspect(Jaylib &jay);
    void printPicker(Jaylib &jay);
    void printMatrix(Jaylib &jay, int8_t x);

    void printSelection(Jaylib &jay);
};
