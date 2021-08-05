#pragma once

#include "jaylib.h"
#include "card.h"
#include "card_data.h"
#include "utils.h"
#include "glyphs.h"
#include "constants.h"

typedef struct {
    uint8_t card;
    uint8_t color;
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
    CardColor board[3][3];

    uint8_t selection;

    uint8_t scores[2];
    Pos cursor;
    Wipe wipes[5];

    void print(Jaylib &jay);

    void startSelect();
    void select_inc(int8_t step=1);

    void moveCursor(int8_t x, int8_t y);

    uint8_t play();

    void ai_find_move();
};

PROGMEM const Pos tonari[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
