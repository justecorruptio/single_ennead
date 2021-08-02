#pragma once

#include "jaylib.h"
#include "card_data.h"
#include "utils.h"

typedef struct {
    uint8_t card;
    uint8_t color;
} CardColor;

class Game {

    public:
    uint8_t cards[2][5];
    CardColor board[3][3];
    uint8_t turn;
    uint8_t selection;
    uint8_t scores[2];

    void print(Jaylib &jay);
};
