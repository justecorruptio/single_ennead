#pragma once

#include "jaylib.h"
#include "card_data.h"
#include "utils.h"
#include "glyphs.h"
#include "constants.h"

typedef struct {
    uint8_t card;
    uint8_t color;
} CardColor;

typedef struct {
    int8_t x;
    int8_t y;
} Pos;

class Game {

    public:
    uint8_t state;

    uint8_t turn;
    uint8_t cards[2][5];
    CardColor board[3][3];

    uint8_t selection;

    uint8_t scores[2];
    Pos cursor;

    void print(Jaylib &jay);

    void start_select(uint8_t player);
    void select_inc(uint8_t player, int8_t step=1);

    void move_cursor(int8_t x, int8_t y);
};
