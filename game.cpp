#include "game.h"

void Game::startSelect() {
    for(int i = 0; i < 5; i++){
        if(cards[turn][i]){
            selection = i;
            return;
        }
    }
}


void Game::select_inc(int8_t step) {
    for(int i = 1; i < 5; i++){
        uint8_t n = (selection + step * i + 5) % 5;
        if(cards[turn][n]) {
            selection = n;
            return;
        }
    }
}

void Game::moveCursor(int8_t x, int8_t y) {
    cursor.x = (cursor.x + x + 3) % 3;
    cursor.y = (cursor.y + y + 3) % 3;
}

uint8_t Game::play() {
    uint8_t x = cursor.x, y = cursor.y;
    if(board[x][y].card) return 0;

    uint8_t color = 1 - turn;

    board[x][y] = {cards[turn][selection], color};
    cards[turn][selection] = 0;
    scores[turn] += 1;

    Strength my_s = CARDS[board[x][y].card].strength();

    for(int i = 0; i < 4; i++ ){
        int8_t dx = x + pgm_read_byte(&(tonari[i].x));
        int8_t dy = y + pgm_read_byte(&(tonari[i].y));
        if(dx < 0 || dy < 0 || dx > 2 || dy >  2) continue;
        if(board[dx][dy].card == 0) continue;
        if(color == board[dx][dy].color) continue;

        Strength their_s = CARDS[board[dx][dy].card].strength();
        if(my_s.dir(i) > their_s.dir((i + 2) % 4)) {
            board[dx][dy].color = color;
            scores[turn] += 1;
            scores[1 - turn] -= 1;
        }
    }

    return 1;
}

void Game::ai_find_move() { //set cursor and selection
    uint8_t color = 1 - turn;
    int8_t best_flips = -1;

    for(int idx = 0; idx < 5; idx ++) {
        if (cards[turn][idx] == 0) continue;
        Strength my_s = CARDS[cards[turn][idx]].strength();
        for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++) {
                if(board[x][y].card) continue;
                int8_t flips = 0;
                for(int i = 0; i < 4; i++ ){
                    int8_t dx = x + pgm_read_byte(&(tonari[i].x));
                    int8_t dy = y + pgm_read_byte(&(tonari[i].y));
                    if(dx < 0 || dy < 0 || dx > 2 || dy >  2) continue;
                    if(board[dx][dy].card == 0) continue;
                    if(color == board[dx][dy].color) continue;

                    Strength their_s = CARDS[board[dx][dy].card].strength();
                    if(my_s.dir(i) > their_s.dir((i + 2) % 4)) {
                        flips ++;
                    }
                }
                if (flips > best_flips) {
                    cursor = {x, y};
                    selection = idx;
                    best_flips = flips;
                }
            }
        }
    }
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
        jay.drawCursorBox(cursor.x * 19 + 35, cursor.y * 21, 19, 21);
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


