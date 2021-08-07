#include "jaylib.h"
#include "utils.h"

#include "card.h"
#include "card_data.h"

#include "game.h"
#include "collection.h"
#include "constants.h"

Jaylib jay;
Game game = Game();
Collection collection = Collection();
// uint8_t state = STATE_USER_SELECT;
//uint8_t state = STATE_COLLECTION_INSPECT;
uint8_t state = STATE_COLLECTION_PICKER;

void setup() {
    jay.boot();
    jay.invert(1);
    jay.clear();

    collection.init();

    game = Game();
    game.startSelect();
    game.state = STATE_USER_SELECT;

    game.cards[0][0] = 1;
    game.cards[0][1] = 2;
    game.cards[0][2] = 3;
    game.cards[0][3] = 4;
    game.cards[0][4] = 10;

    game.cards[1][0] = 1;
    game.cards[1][1] = 2;
    game.cards[1][2] = 3;
    game.cards[1][3] = 4;
    game.cards[1][4] = 5;

    //game.turn = 1;
}

// animation vars;
uint16_t accum = 0;
uint8_t temp = 0;

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
        if(jay.justPressed(UP_BUTTON)) game.moveCursor(0, -1);
        if(jay.justPressed(DOWN_BUTTON)) game.moveCursor(0, 1);
        if(jay.justPressed(LEFT_BUTTON)) game.moveCursor(-1, 0);
        if(jay.justPressed(RIGHT_BUTTON)) game.moveCursor(1, 0);
        if(jay.justPressed(A_BUTTON)) {
            uint8_t success = game.play();
            if(success) {
                game.turn = 1 - game.turn;
                game.ai_find_move();
                game.state = state = STATE_ENEMY_SELECT;
                temp = game.selection;
                accum = 0;
            }
        }
        if(jay.justPressed(B_BUTTON)) {
            game.state = state = STATE_USER_SELECT;
        }
        break;
    case STATE_ENEMY_SELECT:
        if(jay.counter % 16 == 0) {
            accum ++;
            game.select_inc();
        }
        if (accum > 3 && game.selection == temp) {
            game.play();
            game.turn = 1 - game.turn;
            game.startSelect();
            game.state = state = STATE_USER_SELECT;
        }
        break;

    case STATE_COLLECTION_INSPECT:
        if(jay.justPressed(UP_BUTTON)) collection.moveCursor(0, -1);
        if(jay.justPressed(DOWN_BUTTON)) collection.moveCursor(0, 1);
        if(jay.justPressed(LEFT_BUTTON)) collection.moveCursor(-1, 0);
        if(jay.justPressed(RIGHT_BUTTON)) collection.moveCursor(1, 0);
        break;
    case STATE_COLLECTION_PICKER:
        if(jay.justPressed(UP_BUTTON)) collection.moveCursor(0, -1);
        if(jay.justPressed(DOWN_BUTTON)) collection.moveCursor(0, 1);
        if(jay.justPressed(LEFT_BUTTON)) collection.moveCursor(-1, 0);
        if(jay.justPressed(RIGHT_BUTTON)) collection.moveCursor(1, 0);
        if(jay.justPressed(A_BUTTON)) collection.selectCard();
        if(jay.justPressed(B_BUTTON)) collection.deselectCard();
        break;
    }

    switch(state) {
        case STATE_USER_SELECT:
        case STATE_USER_HOVER:
        case STATE_ENEMY_SELECT:
            game.print(jay);
            break;
        case STATE_COLLECTION_INSPECT:
            collection.printInspect(jay);
            break;
        case STATE_COLLECTION_PICKER:
            collection.printPicker(jay);
            collection.printSelection(jay);
            break;
    }

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

    //jay.smallPrint(99, 56, itoa(jay.cpuLoad()), 1);

    jay.display();
}

// vim:syntax=c
