#include "game.h"

void Game::print(Jaylib &jay) {
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 3; j ++) {
            CardColor cc = board[i][j];
            if(cc.card) {
                CARDS[cc.card].print(jay, i * 19 + 36, j * 21 + 1, cc.color);
            } else {
                jay.drawFastHLine(i * 19 + 36, j * 21 + 1, 3, 1);
                jay.drawFastVLine(i * 19 + 36, j * 21 + 1, 3, 1);
                jay.drawFastHLine(i * 19 + 51, j * 21 + 1, 3, 1);
                jay.drawFastVLine(i * 19 + 53, j * 21 + 1, 3, 1);
                jay.drawFastHLine(i * 19 + 36, j * 21 + 20, 3, 1);
                jay.drawFastVLine(i * 19 + 36, j * 21 + 18, 3, 1);
                jay.drawFastHLine(i * 19 + 51, j * 21 + 20, 3, 1);
                jay.drawFastVLine(i * 19 + 53, j * 21 + 18, 3, 1);
            }
        }
    }
    for(int i = 0; i < 5; i++) {
        if(cards[0][i]) {
            jay.drawFastHLine(1, i * 13, 16, 0);
            CARDS[cards[0][i]].print(jay, 1, i * 13 + 1, 1);
        }
    }
}
