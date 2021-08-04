#include "jaylib.h"
#include "utils.h"

#include "card.h"
#include "card_data.h"

#include "game.h"
#include "constants.h"

Jaylib jay;
Game game = Game();
uint8_t state = STATE_USER_SELECT;

void setup() {
    jay.boot();
    jay.invert(1);
    jay.clear();

    game = Game();
    game.start_select();
    game.state = STATE_USER_SELECT;

    /*
    game.board[2][1] = {2,0};
    game.board[1][2] = {4,0};
    game.board[1][0] = {4,0};
    game.board[0][1] = {4,0};

    game.cards[0][0] = 1;
    game.cards[0][1] = 2;
    //game.cards[0][2] = 3;
    game.cards[0][3] = 4;
    game.cards[0][4] = 5;

    game.cards[1][0] = 0;
    game.cards[1][1] = 1;
    game.cards[1][2] = 1;
    game.cards[1][3] = 1;
    game.cards[1][4] = 1;
    */

    game.cards[0][0] = 1;
    game.cards[0][1] = 2;
    game.cards[0][2] = 3;
    game.cards[0][3] = 4;
    game.cards[0][4] = 5;

    game.cards[1][0] = 1;
    game.cards[1][1] = 2;
    game.cards[1][2] = 3;
    game.cards[1][3] = 4;
    game.cards[1][4] = 5;

    game.scores[0] = 3;
    game.scores[1] = 2;

    //game.turn = 1;
}


void loop() {
    if(!jay.nextFrame()) return;

    jay.clear();
    jay.pollButtons();

    switch (state) {
    case STATE_USER_SELECT:
        if(jay.justPressed(UP_BUTTON)) game.select_inc(-1);
        if(jay.justPressed(DOWN_BUTTON)) game.select_inc(1);
        if(jay.justPressed(A_BUTTON)) {
            game.state = state = STATE_USER_HOVER;
        }
        break;
    case STATE_USER_HOVER:
        if(jay.justPressed(UP_BUTTON)) game.move_cursor(0, -1);
        if(jay.justPressed(DOWN_BUTTON)) game.move_cursor(0, 1);
        if(jay.justPressed(LEFT_BUTTON)) game.move_cursor(-1, 0);
        if(jay.justPressed(RIGHT_BUTTON)) game.move_cursor(1, 0);
        if(jay.justPressed(A_BUTTON)) {
            uint8_t success = game.play();
            if(success) {
                game.turn = 1 - game.turn;
                game.ai_find_move();
                //game.cursor= {0, 0};
                //game.selection = 0;
                game.play();

                game.turn = 1 - game.turn;
                game.start_select();
                //game.state = state = STATE_ENEMY_SELECT;
                game.state = state = STATE_USER_SELECT;
            }
        }
        if(jay.justPressed(B_BUTTON)) {
            game.state = state = STATE_USER_SELECT;
        }
        break;
    }


    game.print(jay);

    /*
    for(int i =0; i < 2000; i++) {
        jay.drawFastVLine(102, 24, 8, 1);
        jay.drawFastVLine(102, 24, 8, 0);

        jay.drawFastVLine(101, 24, 28, 1);
        jay.drawFastVLine(101, 24, 26, 0);

        jay.drawFastVLine(100, 22, 28, 1);
        jay.drawFastVLine(100, 23, 26, 0);
    }
    */

    jay.smallPrint(99, 56, itoa(jay.cpuLoad()), 1);

    jay.display();
}

// vim:syntax=c
