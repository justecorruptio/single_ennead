#include "main_menu.h"

void MainMenu::print(Jaylib &jay) {
    if (pan > 0) {
        if (jay.counter % 2 == 0) pan --;
    }
    uint8_t pos = pan > 20? 20: pan;
    jay.drawBand(15, pos + 3, GLYPH_MAIN_LOGO1, 98, 1);
    jay.drawBand(15, pos + 11, GLYPH_MAIN_LOGO2, 98, 1);
}

void MainMenu::reset() {
    pan = 40;
}
