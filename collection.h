#pragma once

#include "utils.h"
#include "jaylib.h"
#include "glyphs.h"
#include "card.h"
#include "constants.h"

#define COLLECTION_MAGIC 0xf493

typedef union {
    uint16_t v;
    struct {
        uint8_t win:2;
        uint8_t payout:2;
        uint8_t play:2;
        uint8_t setup:2;
        uint8_t visibility:2;
        uint8_t capture:2;
        uint8_t display:2;
        uint8_t _reserved:2;
    };
} Rules;

class Collection {

    public:
    Pos cursor;

    uint8_t cards[5];
    uint8_t numCards;

    void init();
    uint8_t hasCard(uint8_t n);
    uint8_t numCollected();

    uint16_t getMoney();
    void setMoney(uint16_t money);

    Rules getRules();
    void setRule(uint8_t rule);
    uint8_t checkRule(uint8_t rule);

    void resetPicker();
    void moveCursor(int8_t x, int8_t y);
    void selectCard();
    void deselectCard();

    void printInspect(Jaylib &jay);
    void printPicker(Jaylib &jay);
    void printMatrix(Jaylib &jay, int8_t x);

    void printSelection(Jaylib &jay);
};
