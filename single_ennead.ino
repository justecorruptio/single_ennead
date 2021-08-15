#include "jaylib.h"
#include "utils.h"

#include "card.h"
#include "card_data.h"

#include "game.h"
#include "collection.h"
#include "constants.h"
#include "main_menu.h"

Jaylib jay;
Game game;
Collection collection;
MainMenu main_menu;

// uint8_t state = STATE_USER_SELECT;
//uint8_t state = STATE_COLLECTION_INSPECT;
//uint8_t state = STATE_COLLECTION_PICKER;
//uint8_t state = STATE_COLLECTION_OUTCOME;
uint8_t state = STATE_MAIN_MENU;

void setup() {
    jay.boot();
    jay.invert(1);
    jay.clear();

    collection.init();

    main_menu.reset();
    jay.initRandomSeed();

    //collection.deleteCard(99);

    /*
    collection.result = 0;
    collection.payout = 4620;
    collection.bonus = 45;
    collection.winCard = 57;
    collection.loseCard = 99;
    */

    //game.reset();
    //state = game.state;
}

// animation vars;
uint8_t accum = 0;
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
                if(game.isOver()) {
                    collection.setOutcome(game.result());
                    state = STATE_GAME_OVER;
                    break;
                }
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
            if(game.isOver()) {
                collection.setOutcome(game.result());
                state = STATE_GAME_OVER;
                break;
            }
            game.turn = 1 - game.turn;
            game.startSelect();
            game.state = state = STATE_USER_SELECT;
        }
        break;

    case STATE_GAME_OVER:
        if(jay.justPressed(A_BUTTON) || jay.justPressed(B_BUTTON)) {
            state = STATE_COLLECTION_OUTCOME;
        }
        break;

    case STATE_COLLECTION_INSPECT:
        if(jay.justPressed(UP_BUTTON)) collection.moveCursor(0, -1);
        if(jay.justPressed(DOWN_BUTTON)) collection.moveCursor(0, 1);
        if(jay.justPressed(LEFT_BUTTON)) collection.moveCursor(-1, 0);
        if(jay.justPressed(RIGHT_BUTTON)) collection.moveCursor(1, 0);
        if(jay.justPressed(A_BUTTON)) {
            if(collection.canBuy()) {
                state = STATE_COLLECTION_BUY_CONFIRM;
            }
        }
        if(jay.justPressed(B_BUTTON)) {
            state = STATE_MAIN_MENU;
        }
        break;
    case STATE_COLLECTION_PICKER:
        if(jay.justPressed(UP_BUTTON)) collection.moveCursor(0, -1);
        if(jay.justPressed(DOWN_BUTTON)) collection.moveCursor(0, 1);
        if(jay.justPressed(LEFT_BUTTON)) collection.moveCursor(-1, 0);
        if(jay.justPressed(RIGHT_BUTTON)) collection.moveCursor(1, 0);
        if(jay.justPressed(A_BUTTON)) {
            collection.selectCard();
            if(collection.numCards == 5) {
                state = STATE_COLLECTION_PICK_CONFIRM;
            }
        }
        if(jay.justPressed(B_BUTTON)) {
            if(collection.numCards == 0) {
                state = STATE_MAIN_MENU;
            } else {
                collection.deselectCard();
            }
        }
        break;
    case STATE_COLLECTION_PICK_CONFIRM:
        if(jay.justPressed(A_BUTTON)) {
            collection.selectAICards();
            game.reset(collection);
            state = game.state;
        }
        if(jay.justPressed(B_BUTTON)) {
            state = STATE_COLLECTION_PICKER;
        }
        break;

    case STATE_COLLECTION_OUTCOME:
        if(jay.justPressed(A_BUTTON) || jay.justPressed(B_BUTTON)) {
            collection.resetPicker();
            state = STATE_MAIN_MENU;
        }
        break;
    case STATE_COLLECTION_BUY_CONFIRM:
        if(jay.justPressed(A_BUTTON)) {
            collection.buy();
            state = STATE_COLLECTION_INSPECT;
        }
        if(jay.justPressed(B_BUTTON)) {
            state = STATE_COLLECTION_INSPECT;
        }
        break;
    case STATE_MAIN_MENU:
        main_menu.print(jay, collection.numCollected());
        if(main_menu.pan > 0) break;
        if(jay.justPressed(UP_BUTTON)) main_menu.cursorInc(-1);
        if(jay.justPressed(DOWN_BUTTON)) main_menu.cursorInc(1);
        if(jay.justPressed(A_BUTTON)) {
            switch(main_menu.cursor){
            case 0:
                state = STATE_COLLECTION_PICKER;
                break;
            case 1:
                state = STATE_COLLECTION_INSPECT;
                break;
            }
        }
        break;
    }

    switch(state) {
        case STATE_USER_SELECT:
        case STATE_USER_HOVER:
        case STATE_ENEMY_SELECT:
        case STATE_GAME_OVER:
            game.print(jay);
            break;
        case STATE_COLLECTION_INSPECT:
        case STATE_COLLECTION_BUY_CONFIRM:
            collection.printInspect(jay);
            break;
        case STATE_COLLECTION_PICKER:
        case STATE_COLLECTION_PICK_CONFIRM:
            collection.printPicker(jay);
            collection.printSelection(jay);
            break;
        case STATE_COLLECTION_OUTCOME:
            collection.printOutcome(jay);
            break;
    }

    if (state == STATE_GAME_OVER) {
        switch(game.result()) {
        case -1: jay.drawPrompt(14, "You Lose", 0); break;
        case 0: jay.drawPrompt(14, "Draw", 0); break;
        case 1: jay.drawPrompt(14, "You Win", 0); break;
        }
    }

    if (state == STATE_COLLECTION_PICK_CONFIRM) {
        jay.drawPrompt(22, "Ready?", 0);
    }

    if (state == STATE_COLLECTION_BUY_CONFIRM) {
        jay.drawPrompt(40, "Buy Card?", 0);
    }

    //jay.smallPrint(99, 56, itoa(jay.cpuLoad()), 1);
    //jay.smallPrint(99, 1, itoa(collection.numCollected()), 1);
    //jay.smallPrint(99, 1, itoa(collection.getRules().v,16), 1);

    jay.display();
}

// vim:syntax=c
