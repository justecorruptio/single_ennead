#include "game.h"

void Game::start_select(uint8_t player) {
    for(int i = 0; i < 5; i++){
        if(cards[player][i]){
            selection = i;
            return;
        }
    }
}


void Game::select_inc(uint8_t player, int8_t step) {
    for(int i = 1; i < 5; i++){
        uint8_t n = (selection + step * i + 5) % 5;
        if(cards[player][n]) {
            selection = n;
            return;
        }
    }
}

void Game::move_cursor(int8_t x, int8_t y) {
    cursor.x = (cursor.x + x + 3) % 3;
    cursor.y = (cursor.y + y + 3) % 3;
}

void Game::print(Jaylib &jay) {
    // DISPLAY BOARD
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

    // DISPLAY CURSOR
    if(state == STATE_USER_HOVER) {
        uint8_t c = (jay.counter / 4) % 4;

        for(int i=0; i<20; i++) {
            jay.drawPixel(cursor.x * 19 + 35 + i, cursor.y * 21, (c - i + 100) % 3 == 1);
            jay.drawPixel(cursor.x * 19 + 35 + i, cursor.y * 21 + 21, (c + i) % 3 == 0);
        }
        for(int i=0; i<22; i++) {
            jay.drawPixel(cursor.x * 19 + 35, cursor.y * 21 + i, (c + i) % 3 == 1);
            jay.drawPixel(cursor.x * 19 + 54, cursor.y * 21 + i, (c - i + 100) % 3 == 0);
        }
        //jay.drawBand(cursor.x * 19 + 38, cursor.y * 21 + 11 + c, GLYPH_CURSOR, 5, 1);
    }

    // DISPLAY SELECTIONS
    for(int i = 0; i < 5; i++) {
        if(cards[0][i]) {
            uint8_t selected = turn == 0 && selection == i;
            jay.drawFastHLine(selected * 4 + 1, i * 12, 18, 0);
            jay.drawFastVLine(selected * 4 + 19, i * 12, 20, 0);
            jay.drawFastVLine(selected * 4, i * 12, 20, 0);
            CARDS[cards[0][i]].print(jay, selected * 4 + 1, i * 12 + 1, 1);

            if(selected && state == STATE_USER_SELECT) {
                uint8_t c = (jay.counter / 4) % 4;
                jay.smallPrint(24 + c, i * 12 + 1, "<", 1);
            }
        }

        if(cards[1][i]) {
            uint8_t selected = turn == 1 && selection == i && state == STATE_ENEMY_SELECT;
            jay.drawFastHLine(selected * -4 + 109, i * 12, 18, 0);
            jay.drawFastVLine(selected * -4 + 127, i * 12, 20, 0);
            jay.drawFastVLine(selected * -4 + 108, i * 12, 20, 0);
            CARDS[cards[1][i]].printBack(jay, selected * -4 + 109, i * 12 + 1, 0);
        }
    }


    // DISPLAY SCORES
    jay.largePrint(30, 56, itoa(scores[0]), 1);
    jay.largePrint(93, 56, itoa(scores[1]), 1);
}
