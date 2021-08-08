#include "main_menu.h"

void MainMenu::print(Jaylib &jay, uint8_t numCollected) {
    uint8_t pos = pan > 20? 20: pan;
    jay.drawBand(15, pos + 7, GLYPH_MAIN_LOGO1, 98, 1);
    jay.drawBand(15, pos + 15, GLYPH_MAIN_LOGO2, 98, 1);
    if (pan > 0) {
        if (jay.counter % 2 == 0) pan --;
        return;
    }
    jay.largePrint(22, 30, "Play: ", 1, 1);
    char buff[] = "X League";
    buff[0] = "FDCBASXYZ\x7f"[(numCollected - 1) / 10];
    jay.largePrint(58, 30, buff, 1, 1);

    jay.largePrint(34, 40, "Collection", 1, 1);
    jay.largePrint(22, 50, "Queen of Cards", 1, 1);

    jay.drawCursorBox(20, cursor * 10 + 28, 86, 10);

}

void MainMenu::cursorInc(int8_t step) {
    cursor = (cursor + step + 3) % 3;
}

void MainMenu::reset() {
    pan = 40;
    cursor = 0;
}
