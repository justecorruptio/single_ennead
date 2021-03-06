PROGMEM const char RULE_STRING_00[] = "WIN: RANDOM";
PROGMEM const char RULE_STRING_01[] = "WIN: LOWEST";
PROGMEM const char RULE_STRING_02[] = "WIN: HIGHEST";

PROGMEM const char RULE_STRING_10[] = "PAYOUT: 1X";
PROGMEM const char RULE_STRING_11[] = "PAYOUT: 2X";
PROGMEM const char RULE_STRING_12[] = "PAYOUT: 3X";
PROGMEM const char RULE_STRING_13[] = "PAYOUT: 4X";

PROGMEM const char RULE_STRING_20[] = "PLAY: CHOOSE";
PROGMEM const char RULE_STRING_21[] = "PLAY: ORDER";
PROGMEM const char RULE_STRING_22[] = "PLAY: RANDOM";

PROGMEM const char RULE_STRING_30[] = "SETUP: NONE";
PROGMEM const char RULE_STRING_31[] = "SETUP: SWAP";
PROGMEM const char RULE_STRING_32[] = "SETUP: REPLACE";

PROGMEM const char RULE_STRING_40[] = "VISIBILITY: HIDDEN";
PROGMEM const char RULE_STRING_41[] = "VISIBILITY: OPEN";
PROGMEM const char RULE_STRING_42[] = "VISIBILITY: THREE";

PROGMEM const char RULE_STRING_50[] = "CAPTURE: NORMAL";
PROGMEM const char RULE_STRING_51[] = "CAPTURE: FALLEN ACE";
PROGMEM const char RULE_STRING_52[] = "CAPTURE: SAME";
PROGMEM const char RULE_STRING_53[] = "CAPTURE: ATTACKER";

//PROGMEM const char RULE_STRING_60[] = "DISPLAY: NORMAL";
//PROGMEM const char RULE_STRING_61[] = "DISPLAY: MEMORY";

PROGMEM const char* const RULE_STRINGS[][4] = {
    {RULE_STRING_00, RULE_STRING_01, RULE_STRING_02},
    {RULE_STRING_10, RULE_STRING_11, RULE_STRING_12, RULE_STRING_13},
    {RULE_STRING_20, RULE_STRING_21, RULE_STRING_22},
    {RULE_STRING_30, RULE_STRING_31, RULE_STRING_32},
    {RULE_STRING_40, RULE_STRING_41, RULE_STRING_42},
    {RULE_STRING_50, RULE_STRING_51, RULE_STRING_52, RULE_STRING_53},
    //{RULE_STRING_60, RULE_STRING_61},
};

#define NUM_RULES 19

PROGMEM const uint8_t RULES_LIST[] = {
    RULE_WIN_RANDOM, RULE_WIN_LOWEST, RULE_WIN_HIGHEST,
    RULE_PAYOUT_NORMAL, RULE_PAYOUT_DOUBLE, RULE_PAYOUT_TRIPLE, RULE_PAYOUT_QUAD,
    RULE_PLAY_CHOOSE, RULE_PLAY_ORDER, RULE_PLAY_RANDOM,
    RULE_SETUP_NONE, RULE_SETUP_SWAP, RULE_SETUP_REPLACE,
    RULE_VISIBILITY_HIDDEN, RULE_VISIBILITY_OPEN, RULE_VISIBILITY_THREE,
    RULE_CAPTURE_NORMAL, RULE_CAPTURE_FALLEN_ACE, /*RULE_CAPTURE_SAME,*/ RULE_CAPTURE_ATTACKER,
//    RULE_DISPLAY_NORMAL, RULE_DISPLAY_MEMORY,
};
