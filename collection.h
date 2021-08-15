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

    uint8_t my_cards[5];
    uint8_t ai_cards[5];
    uint8_t numCards;

    int8_t result;
    uint16_t payout;
    uint16_t bonus;
    uint8_t winCard;
    uint8_t loseCard;

    void init();
    uint8_t hasCard(uint8_t n);
    void addCard(uint8_t n);
    void deleteCard(uint8_t n);
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

    void selectAICards();

    void setOutcome(int8_t _result);

    uint8_t canBuy();
    void buy();

    void printInspect(Jaylib &jay);
    void printPicker(Jaylib &jay);
    void printMatrix(Jaylib &jay, int8_t x);

    void printSelection(Jaylib &jay);
    void printOutcome(Jaylib &jay);
};
