#pragma once

#define STATE_USER_SELECT 1
#define STATE_USER_HOVER 2
#define STATE_ENEMY_SELECT 3
#define STATE_GAME_OVER 4

#define STATE_COLLECTION_INSPECT 10
#define STATE_COLLECTION_PICKER 11
#define STATE_COLLECTION_PICK_CONFIRM 12
#define STATE_COLLECTION_OUTCOME 13
#define STATE_COLLECTION_BUY_CONFIRM 14

#define STATE_MAIN_MENU 20


#define RULE_WIN_RANDOM 0x00
#define RULE_WIN_LOWEST 0x01
#define RULE_WIN_HIGHEST 0x02

#define RULE_PAYOUT_NORMAL 0x10
#define RULE_PAYOUT_DOUBLE 0x11
#define RULE_PAYOUT_TRIPLE 0x12

#define RULE_PLAY_CHOOSE 0x20
#define RULE_PLAY_ORDER 0x21
#define RULE_PLAY_RANDOM 0x22

#define RULE_SETUP_NONE 0x30
#define RULE_SETUP_SWAP 0x31
#define RULE_SETUP_REPLACE 0x32

#define RULE_VISIBILITY_HIDDEN 0x40
#define RULE_VISIBILITY_OPEN 0x41
#define RULE_VISIBILITY_THREE 0x42

#define RULE_CAPTURE_NORMAL 0x50
#define RULE_CAPTURE_FALLEN_ACE 0x51
#define RULE_CAPTURE_SAME 0x52
#define RULE_CAPTURE_ATTACKER 0x53

#define RULE_DISPLAY_NORMAL 0x60
#define RULE_DISPLAY_MEMORY 0x61
