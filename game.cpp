#include "game.h"

void Game::print(Jaylib &jay) {
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 3; j ++) {
            CardColor cc = board[i][j];
            if(cc.card) {
                CARDS[cc.card].print(jay, i * 19 + 36, j * 21 + 1, cc.color);
            } else {
                jay.drawBand(i * 19 + 36, j * 21 + 1, GLYPH_ANGLES, 3, 1);
                jay.drawBand(i * 19 + 51, j * 21 + 1, GLYPH_ANGLES + 1, 3, 1);
                jay.drawBand(i * 19 + 36, j * 21 + 18, GLYPH_ANGLES + 3, 3, 1);
                jay.drawBand(i * 19 + 51, j * 21 + 18, GLYPH_ANGLES + 4, 3, 1);
            }
        }
    }
    for(int i = 0; i < 5; i++) {
        if(cards[0][i]) {
            uint8_t selected = turn == 0 && selection == i;
            jay.drawFastHLine(selected * 4 + 1, i * 12, 18, 0);
            jay.drawFastVLine(selected * 4 + 19, i * 12, 20, 0);
            jay.drawFastVLine(selected * 4, i * 12, 20, 0);
            CARDS[cards[0][i]].print(jay, selected * 4 + 1, i * 12 + 1, 1);

            if(selected) {
                uint8_t c = (jay.counter / 4) % 4;
                jay.smallPrint(24 + c, i * 12 + 1, "<", 1);
            }
        }

        if(cards[1][i]) {
            uint8_t selected = turn == 1 && selection == i;
            jay.drawFastHLine(selected * -4 + 109, i * 12, 18, 0);
            jay.drawFastVLine(selected * -4 + 127, i * 12, 20, 0);
            jay.drawFastVLine(selected * -4 + 108, i * 12, 20, 0);
            CARDS[cards[1][i]].printBack(jay, selected * -4 + 109, i * 12 + 1, 0);
        }
    }
    jay.largePrint(30, 56, itoa(scores[0]), 1);
    jay.largePrint(93, 56, itoa(scores[1]), 1);
}
