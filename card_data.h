#pragma once

#define CC(a1,a2,a3,a4,a5,a6,a7,a8,e,s,...) \
    {{0x##a1,0x##a2,0x##a3,0x##a4,0x##a5,0x##a6,0x##a7,0x##a8},0x##e,0x##s,__VA_ARGS__}

#define CC_PLACEHOLDER \
    CC(ff,ff,ff,ff,ff,ff,ff,ff, 00,aaaa)

PROGMEM const CardData CARDS [] = {
    CC_PLACEHOLDER,

    // 01 - 10
    CC(01,06,78,89,8e,88,88,70, 35,1111), // Ant
    CC(1c,22,e1,a1,a1,e1,22,1c, 23,2327), // Mushroom
    CC(78,84,82,81,85,89,8a,74, 25,1111), // Goo
    CC(76,89,8d,81,8e,81,4d,32, 25,567A), // Bunny
    CC(73,8d,89,8e,89,79,91,ef, 15,1234), // Butterfly
    CC(3e,41,c1,a2,a2,a1,99,76, 13,1111), // Mouse
    CC(38,44,82,81,81,81,42,3c, 24,1214), // Slime
    CC(7b,45,87,84,86,c9,75,03, 14,1111), // Wisp
    CC(78,84,84,84,8e,85,45,38, 25,1111), // Apple
    CC(0e,11,11,f1,91,ce,a0,60, 12,1111), // Dandelion
    CC(3f,61,a1,a1,a1,bf,c2,fc, 12,1111), // Brick
    CC(71,8e,89,8e,88,74,44,38, 15,1111), // Bumble Bee
    CC(38,48,86,99,a1,bd,e3,be, 02,1111), // Snail
    CC(38,c4,c6,45,45,f9,c2,7c, 14,1111), // Turtle
    CC(38,c4,46,c4,44,22,49,36, 14,1111), // Angler Fish
    CC(62,95,8d,85,82,8d,95,62, 25,1111), // Sprout
    CC(38,47,82,84,84,82,47,38, 24,1234), // Kitty Cat
    CC(1e,11,d1,91,f1,11,11,1e, 22,1111), // Umbrella
    CC(ce,b1,51,51,91,ae,a0,40, 12,1111), // Baby
    CC(36,5d,63,22,e2,e3,5d,36, 23,1111), // Flower
    CC(6c,92,31,51,91,31,49,96, 22,1111), // Jellyfish
    CC(38,44,82,81,81,87,49,32, 24,89AA), // Water Sprite
    CC(0e,11,31,51,b1,af,84,78, 12,1111), // Iguana
    CC(20,6e,91,b1,91,91,6e,20, 22,1111), // Snowman
    CC(1f,21,42,e2,a2,d9,97,60, 13,1111), // Chihuahua
    CC(70,90,fe,a1,a1,f1,91,fe, 32,1111), // Chair
    CC(30,2e,61,91,91,b1,ae,60, 22,1111), // Duck
    CC(30,ce,91,b1,b1,91,ce,30, 22,1111), // Child
    CC(7c,82,61,81,61,81,72,0c, 23,1111), // Squid
    CC(0e,71,91,d1,51,4f,88,fc, 12,1111), // Puppy
    CC(60,5e,41,41,c1,c1,5e,60, 23,1111), // Bell Monster
    CC(e0,90,4e,21,71,91,91,ee, 32,1111), // Vulture
    CC(77,89,c2,c4,84,82,49,37, 24,1111), // Dingo
    CC(7f,c1,c1,c1,c1,ff,81,7e, 13,1111), // Book Monster
    CC(08,6e,91,91,b1,d1,8f,01, 22,1111), // Cardinal
    CC(1f,71,91,91,b1,df,04,0e, 12,1111), // Automaton
    CC(1e,21,e2,a2,a2,a2,91,2e, 23,1111), // Cow
    CC(6e,91,91,91,71,8e,80,70, 12,1111), // Chimp
    CC(fc,82,81,81,83,fd,82,fc, 13,1111), // Gravestone
    CC(0e,d1,b1,b1,b1,81,62,1c, 22,1111), // Screamer
    CC(7b,c5,c2,84,44,32,0d,03, 14,5538), // Jackal
    CC(70,89,8f,81,85,8f,89,70, 25,1111), // Flask
    CC(7e,a1,83,a2,82,e3,41,3e, 23,1111), // Hippo
    CC(3d,62,a1,e1,21,61,a2,dd, 23,1111), // Floater
    CC(7e,b7,d3,c2,92,b3,47,3e, 25,1111), // Panda
    CC(7e,91,f1,71,91,f1,21,1e, 22,1111), // Walrus
    CC(7c,82,81,81,85,8b,81,7e, 25,1111), // Rock Monster
    CC(b8,c4,44,44,c4,59,e3,3e, 14,4734), // Scorpion
    CC(e0,a1,ef,51,51,f1,b1,ee, 32,1111), // Cyclist
    CC(0e,11,b1,d1,91,6e,32,0e, 12,1111), // Wasp
    CC(7e,81,c5,c6,86,45,31,0e, 24,1111), // Ox
    CC(02,9f,d1,71,71,d1,9f,02, 22,1111), // Android
    CC(fc,42,81,41,81,41,82,fc, 23,8888), // Ghost
    CC(7e,c3,c1,81,43,3d,22,1c, 13,1111), // Hound
    CC(3f,41,c2,c4,84,42,31,0f, 24,1111), // Fox
    CC(1e,a1,e2,a2,a1,9e,88,70, 13,1111), // Lynx
    CC(18,26,31,f1,a1,81,41,3e, 32,1111), // Hag
    CC(78,8c,8e,8e,8f,ff,79,02, 15,1111), // Jester
    CC(0e,31,41,c1,51,cf,64,1c, 12,1111), // Chocobo
    CC(18,70,dc,82,83,42,22,1d, 33,1111), // Rhino
    CC(1c,22,e2,a2,a3,9d,81,fe, 13,1111), // Hunchback
    CC(0c,7b,89,89,89,89,89,7e, 35,1111), // Soldier
    CC(0e,d1,31,f1,f1,fe,fc,f0, 12,1111), // Hermit
    CC(70,88,88,8f,89,42,b9,c7, 15,1111), // Whale
    CC(7e,e3,83,a3,a3,83,f3,7e, 23,1111), // Ape
    CC(01,ce,b1,91,41,91,ae,c1, 22,1111), // Elf
    CC(6e,91,81,a1,a1,b1,8e,70, 12,1111), // White Snake
    CC(6e,f1,f1,f1,d1,ce,e0,78, 12,1111), // Black Snake
    CC(70,8f,89,89,89,72,42,3c, 15,1111), // Mohawk
    CC(43,be,91,71,71,51,9e,63, 22,1111), // Leg Monster
    CC(3e,45,c3,c2,82,83,45,3e, 24,1839), // Bear
    CC(1e,71,a1,a1,a1,91,71,0e, 22,1111), // Skull
    CC(7c,82,a2,61,21,2f,31,1e, 13,1111), // Elephant
    CC(0e,11,71,91,91,ae,d1,0f, 12,1111), // Fairy
    CC(1f,11,f1,81,51,9e,a5,70, 12,1111), // Dinosaur
    CC(3c,42,81,87,89,90,50,38, 14,1111), // Moon Spirit
    CC(78,86,87,87,83,8f,46,38, 25,1111), // Gangster
    CC(70,8c,82,8f,81,8e,44,38, 25,1111), // Fire Sprite
    CC(41,e2,ae,d1,91,d1,91,6e, 32,1111), // Tank
    CC(70,88,89,8f,88,70,a8,f8, 15,1111), // Submarine
    CC(7e,83,8b,83,87,4f,3f,1e, 15,1111), // Triclops
    CC(78,84,82,41,41,b1,2e,40, 14,1111), // Alien
    CC(0e,11,71,91,b1,a2,85,7b, 12,1111), // Dragonet
    CC(de,b1,e1,f1,b1,9e,90,f8, 12,1111), // Sphynx
    CC(40,4e,51,51,d1,b1,8e,78, 22,1111), // Fencer
    CC(0f,71,86,81,86,81,76,0f, 25,1111), // Wood Nymph
    CC(6e,91,b1,f1,91,be,8c,70, 12,1111), // Boxer
    CC(e3,bc,e2,a2,e2,a2,fc,e3, 23,1111), // Robot
    CC(7e,91,81,a1,b1,bf,9e,60, 12,1111), // Lamia
    CC(70,88,8c,8a,89,74,24,12, 15,1111), // Meteor
    CC(c0,ae,71,91,91,71,ae,c0, 22,1111), // Harpy
    CC(3e,63,e3,e3,e3,e7,ff,3e, 13,1111), // Ninja
    CC(3e,71,d1,d1,f1,61,21,1e, 22,1111), // Huntsman
    CC(71,89,87,87,87,8f,8d,71, 25,1111), // Professor
    CC(08,7c,8e,8e,8f,8f,7d,08, 25,1111), // Witch
    CC(75,8f,88,8c,8c,98,ff,75, 15,1111), // Hermes
    CC(0f,79,8a,89,8a,89,7a,0f, 25,1111), // King
    CC(70,8e,89,89,8a,9d,72,3c, 15,1111), // The Pope
    CC(7e,8f,85,88,88,85,7f,3e, 25,1111), // Demon
    CC(02,75,8d,85,85,8d,75,02, 25,1111), // Angel
};

PROGMEM const char CARD_NAME_000[] = "Missing No";

PROGMEM const char CARD_NAME_001[] = "Fire Ant";
PROGMEM const char CARD_NAME_002[] = "Mushroom";
PROGMEM const char CARD_NAME_003[] = "Goo Monster";
PROGMEM const char CARD_NAME_004[] = "Bunny Rabbit";
PROGMEM const char CARD_NAME_005[] = "Butterfly";
PROGMEM const char CARD_NAME_006[] = "Doormouse";
PROGMEM const char CARD_NAME_007[] = "Slime";
PROGMEM const char CARD_NAME_008[] = "Will o' Wisp";
PROGMEM const char CARD_NAME_009[] = "Apple";
PROGMEM const char CARD_NAME_010[] = "Dandelion";
PROGMEM const char CARD_NAME_011[] = "Brick";
PROGMEM const char CARD_NAME_012[] = "Bumble Bee";
PROGMEM const char CARD_NAME_013[] = "Snail";
PROGMEM const char CARD_NAME_014[] = "Tortoise";
PROGMEM const char CARD_NAME_015[] = "Angler Fish";
PROGMEM const char CARD_NAME_016[] = "Sprout";
PROGMEM const char CARD_NAME_017[] = "Kitty Cat";
PROGMEM const char CARD_NAME_018[] = "Umbrella";
PROGMEM const char CARD_NAME_019[] = "Human Baby";
PROGMEM const char CARD_NAME_020[] = "Sun Flower";
PROGMEM const char CARD_NAME_021[] = "Jellyfish";
PROGMEM const char CARD_NAME_022[] = "Water Sprite";
PROGMEM const char CARD_NAME_023[] = "Iguana";
PROGMEM const char CARD_NAME_024[] = "Snowman";
PROGMEM const char CARD_NAME_025[] = "Chihuahua";
PROGMEM const char CARD_NAME_026[] = "Chair";
PROGMEM const char CARD_NAME_027[] = "Duckling";
PROGMEM const char CARD_NAME_028[] = "Human Child";
PROGMEM const char CARD_NAME_029[] = "Giant Squid";
PROGMEM const char CARD_NAME_030[] = "Puppy";
PROGMEM const char CARD_NAME_031[] = "Bell Monster";
PROGMEM const char CARD_NAME_032[] = "Vulture";
PROGMEM const char CARD_NAME_033[] = "Dingo";
PROGMEM const char CARD_NAME_034[] = "Book Monster";
PROGMEM const char CARD_NAME_035[] = "Cardinal";
PROGMEM const char CARD_NAME_036[] = "Automaton";
PROGMEM const char CARD_NAME_037[] = "Heifer";
PROGMEM const char CARD_NAME_038[] = "Chimpanzee";
PROGMEM const char CARD_NAME_039[] = "Grave Stone";
PROGMEM const char CARD_NAME_040[] = "Screamer";
PROGMEM const char CARD_NAME_041[] = "Jackal";
PROGMEM const char CARD_NAME_042[] = "Dewar Flask";
PROGMEM const char CARD_NAME_043[] = "Hippopotamus";
PROGMEM const char CARD_NAME_044[] = "Floater";
PROGMEM const char CARD_NAME_045[] = "Giant Panda";
PROGMEM const char CARD_NAME_046[] = "Walrus";
PROGMEM const char CARD_NAME_047[] = "Rock Monster";
PROGMEM const char CARD_NAME_048[] = "Scorpion";
PROGMEM const char CARD_NAME_049[] = "Cyclist";
PROGMEM const char CARD_NAME_050[] = "Hornet";
PROGMEM const char CARD_NAME_051[] = "Auroch";
PROGMEM const char CARD_NAME_052[] = "Android";
PROGMEM const char CARD_NAME_053[] = "Apparition";
PROGMEM const char CARD_NAME_054[] = "BloodHound";
PROGMEM const char CARD_NAME_055[] = "Artic Fox";
PROGMEM const char CARD_NAME_056[] = "Bobcat";
PROGMEM const char CARD_NAME_057[] = "Old Hag";
PROGMEM const char CARD_NAME_058[] = "Court Jester";
PROGMEM const char CARD_NAME_059[] = "Chocobo";
PROGMEM const char CARD_NAME_060[] = "Rhinoceros";
PROGMEM const char CARD_NAME_061[] = "Hunchback";
PROGMEM const char CARD_NAME_062[] = "Soldier";
PROGMEM const char CARD_NAME_063[] = "Anchorite";
PROGMEM const char CARD_NAME_064[] = "Killer Whale";
PROGMEM const char CARD_NAME_065[] = "Gorilla";
PROGMEM const char CARD_NAME_066[] = "Light Elf";
PROGMEM const char CARD_NAME_067[] = "White Snake";
PROGMEM const char CARD_NAME_068[] = "Black Snake";
PROGMEM const char CARD_NAME_069[] = "Mohawk";
PROGMEM const char CARD_NAME_070[] = "Leg Monster";
PROGMEM const char CARD_NAME_071[] = "Ursine";
PROGMEM const char CARD_NAME_072[] = "Skeleton";
PROGMEM const char CARD_NAME_073[] = "Elephant";
PROGMEM const char CARD_NAME_074[] = "Fairy";
PROGMEM const char CARD_NAME_075[] = "Dinosaur";
PROGMEM const char CARD_NAME_076[] = "Moon Spirit";
PROGMEM const char CARD_NAME_077[] = "Gangster";
PROGMEM const char CARD_NAME_078[] = "Fire Sprite";
PROGMEM const char CARD_NAME_079[] = "Panzer";
PROGMEM const char CARD_NAME_080[] = "Submarine";
PROGMEM const char CARD_NAME_081[] = "Triclops";
PROGMEM const char CARD_NAME_082[] = "Alien";
PROGMEM const char CARD_NAME_083[] = "Dragonet";
PROGMEM const char CARD_NAME_084[] = "Sphynx";
PROGMEM const char CARD_NAME_085[] = "Fencer";
PROGMEM const char CARD_NAME_086[] = "Wood Nymph";
PROGMEM const char CARD_NAME_087[] = "Pugilist";
PROGMEM const char CARD_NAME_088[] = "Robot";
PROGMEM const char CARD_NAME_089[] = "Echidna";
PROGMEM const char CARD_NAME_090[] = "Meteorite";
PROGMEM const char CARD_NAME_091[] = "Banshee";
PROGMEM const char CARD_NAME_092[] = "Assassin";
PROGMEM const char CARD_NAME_093[] = "Huntsman";
PROGMEM const char CARD_NAME_094[] = "Professor";
PROGMEM const char CARD_NAME_095[] = "Sorceress";
PROGMEM const char CARD_NAME_096[] = "Mercury";
PROGMEM const char CARD_NAME_097[] = "King Midas";
PROGMEM const char CARD_NAME_098[] = "The Pope";
PROGMEM const char CARD_NAME_099[] = "Beelzebub";
PROGMEM const char CARD_NAME_100[] = "Azrael";

#define CN(n) \
    CARD_NAME_##n##0,CARD_NAME_##n##1,CARD_NAME_##n##2,CARD_NAME_##n##3,CARD_NAME_##n##4, \
    CARD_NAME_##n##5,CARD_NAME_##n##6,CARD_NAME_##n##7,CARD_NAME_##n##8,CARD_NAME_##n##9

PROGMEM char *const CARD_NAMES [] = {
    CN(00), CN(01), CN(02), CN(03), CN(04), CN(05), CN(06), CN(07), CN(08), CN(09),
    CARD_NAME_100,
};
