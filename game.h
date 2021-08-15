#pragma once

#include "jaylib.h"
#include "card.h"
#include "utils.h"
#include "glyphs.h"
#include "constants.h"
#include "collection.h"

typedef struct {
    uint8_t card:7;
    uint8_t color:1;
} CardColor;

typedef struct {
    Pos pos;
    uint8_t dir; //0 is null, 1234=WNES
} Wipe;

class Game {

    public:
    uint8_t state;

    uint8_t turn;
    uint8_t cards[2][5];
    uint8_t ai_cards[5];
    CardColor board[3][3];

    uint8_t selection;

    uint8_t scores[2];
    Pos cursor;
    //Wipe wipes[5];
    Pos lastPlay;

    void print(Jaylib &jay, Collection &collection);

    void startSelect(Collection &collection);
    void select_inc(Collection &collection, int8_t step=1);

    void reset(Collection &collection);

    void moveCursor(int8_t x, int8_t y);

    uint8_t play();
    uint8_t isOver();
    int8_t result(); // -1 = lose, 0 = draw, 1 = win

    void ai_find_move(Collection &collection);
};

PROGMEM const Pos tonari[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
