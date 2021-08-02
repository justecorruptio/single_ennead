#include "jaylib.h"
#include "utils.h"

#include "card.h"
#include "card_data.h"

Jaylib jay;

void setup() {
    jay.boot();
    jay.invert(1);
    jay.clear();

}

void loop() {
    if(!jay.nextFrame()) return;

    //
    jay.pollButtons();
    jay.clear();

    /*
    if(jay.justPressed(A_BUTTON) || jay.justPressed(B_BUTTON)) {
    }
    */

    CARDS[0].print(jay, 25, 1, 0);
    CARDS[1].print(jay, 44, 1, 1);
    CARDS[2].print(jay, 63, 1, 0);

    CARDS[3].print(jay, 25, 22, 1);
    CARDS[4].print(jay, 44, 22, 0);
    CARDS[5].print(jay, 63, 22, 0);

    CARDS[6].print(jay, 25, 43, 0);
    CARDS[7].print(jay, 44, 43, 0);
    CARDS[8].print(jay, 63, 43, 0);

    jay.smallPrint(100, 1, itoa(jay.cpuLoad()), 1);

    jay.display();
}

// vim:syntax=c
