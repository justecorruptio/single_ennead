#pragma once

#define CC(a1,a2,a3,a4,a5,a6,a7,a8,e,s,...) \
    {{0x##a1,0x##a2,0x##a3,0x##a4,0x##a5,0x##a6,0x##a7,0x##a8},0x##e,0x##s}

PROGMEM const CardData CARDS [] = {
    CC(ff,ff,ff,ff,ff,ff,ff,ff, 00,aaaa), // Missing No
    CC(01,06,78,89,8e,88,88,70, 35,1135), // Ant
    CC(1c,22,e1,a1,a1,e1,22,1c, 23,1621), // Mushroom
    CC(78,84,82,81,85,89,8a,74, 25,4114), // Goo
    CC(76,89,8d,81,8e,81,4d,32, 25,5311), // Bunny
    CC(73,8d,89,8e,89,79,91,ef, 15,4141), // Butterfly
    CC(3e,41,c1,a2,a2,a1,99,76, 13,1216), // Mouse
    CC(38,44,82,81,81,81,42,3c, 24,1117), // Slime
    CC(7b,45,87,84,86,c9,75,03, 14,1262), // Wisp
    CC(78,84,84,84,8e,85,45,38, 25,1234), // Apple
    CC(0e,11,11,f1,91,ce,a0,60, 12,5123), // Dandelion

    CC(3f,61,a1,a1,a1,bf,c2,fc, 12,1137), // Brick
    CC(71,8e,89,8e,88,74,44,38, 15,6222), // Bumble Bee
    CC(38,48,86,99,a1,bd,e3,be, 02,2361), // Snail
    CC(38,c4,c6,45,45,f9,c2,7c, 14,1722), // Turtle
    CC(38,c4,46,c4,44,22,49,36, 14,5214), // Angler Fish
    CC(62,95,8d,85,82,8d,95,62, 25,7311), // Sprout
    CC(38,47,82,84,84,82,47,38, 24,2631), // Kitty Cat
    CC(1e,11,d1,91,f1,11,11,1e, 22,4162), // Umbrella
    CC(ce,b1,51,51,91,ae,a0,40, 12,1417), // Baby
    CC(36,5d,63,22,e2,e3,5d,36, 23,3433), // Flower

    CC(6c,92,31,51,91,31,49,96, 22,2642), // Jellyfish
    CC(38,44,82,81,81,87,49,32, 24,7331), // Water Sprite
    CC(0e,11,31,51,b1,af,84,78, 12,2255), // Iguana
    CC(20,6e,91,b1,91,91,6e,20, 22,5261), // Snowman
    CC(1f,21,42,e2,a2,d9,97,60, 13,1661), // Chihuahua
    CC(70,90,fe,a1,a1,f1,91,fe, 32,2652), // Chair
    CC(30,2e,61,91,91,b1,ae,60, 22,3237), // Duck
    CC(30,ce,91,b1,b1,91,ce,30, 22,6342), // Child
    CC(7c,82,61,81,61,81,72,0c, 23,5235), // Squid
    CC(0e,71,91,d1,51,4f,88,fc, 12,1716), // Puppy

    CC(60,5e,41,41,c1,c1,5e,60, 23,5542), // Bell Monster
    CC(e0,90,4e,21,71,91,91,ee, 32,1375), // Vulture
    CC(77,89,c2,c4,84,82,49,37, 24,4264), // Dingo
    CC(7f,c1,c1,c1,c1,ff,81,7e, 13,7333), // Book Monster
    CC(08,6e,91,91,b1,d1,8f,01, 22,2455), // Cardinal
    CC(1f,71,91,91,b1,df,04,0e, 12,3734), // Automaton
    CC(1e,21,e2,a2,a2,a2,91,2e, 23,5246), // Cow
    CC(6e,91,91,91,71,8e,80,70, 12,4643), // Chimp
    CC(fc,82,81,81,83,fd,82,fc, 13,7217), // Gravestone
    CC(0e,d1,b1,b1,b1,81,62,1c, 22,2276), // Screamer

    CC(7b,c5,c2,84,44,32,0d,03, 14,5427), // Jackal
    CC(70,89,8f,81,85,8f,89,70, 25,7722), // Flask
    CC(7e,a1,83,a2,82,e3,41,3e, 23,3564), // Hippo
    CC(3d,62,a1,e1,21,61,a2,dd, 23,2673), // Floater
    CC(7e,b7,d3,c2,92,b3,47,3e, 25,6156), // Panda
    CC(7e,91,f1,71,91,f1,21,1e, 22,7345), // Walrus
    CC(7c,82,81,81,85,8b,81,7e, 25,2764), // Rock Monster
    CC(b8,c4,44,44,c4,59,e3,3e, 14,5671), // Scorpion
    CC(e0,a1,ef,51,51,f1,b1,ee, 32,4447), // Cyclist
    CC(0e,11,b1,d1,91,6e,32,0e, 12,7552), // Wasp

    CC(7e,81,c5,c6,86,45,31,0e, 24,7373), // Ox
    CC(02,9f,d1,71,71,d1,9f,02, 22,5555), // Android
    CC(fc,42,81,41,81,41,82,fc, 23,2765), // Ghost
    CC(7e,c3,c1,81,43,3d,22,1c, 13,7346), // Hound
    CC(3f,41,c2,c4,84,42,31,0f, 24,2657), // Fox
    CC(1e,a1,e2,a2,a1,9e,88,70, 13,1767), // Lynx
    CC(18,26,31,f1,a1,81,41,3e, 32,4377), // Hag
    CC(78,8c,8e,8e,8f,ff,79,02, 15,6645), // Jester
    CC(0e,31,41,c1,51,cf,64,1c, 12,7536), // Chocobo
    CC(18,70,dc,82,83,42,22,1d, 33,2775), // Rhino

    CC(1c,22,e2,a2,a3,9d,81,fe, 13,8761), // Hunchback
    CC(0c,7b,89,89,89,89,89,7e, 35,3577), // Soldier
    CC(0e,d1,31,f1,f1,fe,fc,f0, 12,7348), // Hermit
    CC(70,88,88,8f,89,42,b9,c7, 15,6466), // Whale
    CC(7e,e3,83,a3,a3,83,f3,7e, 23,3748), // Ape
    CC(01,ce,b1,91,41,91,ae,c1, 22,2768), // Elf
    CC(6e,91,81,a1,a1,b1,8e,70, 12,7556), // White Snake
    CC(6e,f1,f1,f1,d1,ce,e0,78, 12,8744), // Black Snake
    CC(70,8f,89,89,89,72,42,3c, 15,3686), // Mohawk
    CC(43,be,91,71,71,51,9e,63, 22,6827), // Leg Monster

    CC(3e,45,c3,c2,82,83,45,3e, 24,8844), // Bear
    CC(1e,71,a1,a1,a1,91,71,0e, 22,5667), // Skull
    CC(7c,82,a2,61,21,2f,31,1e, 13,5856), // Elephant
    CC(0e,11,71,91,91,ae,d1,0f, 12,4686), // Fairy
    CC(1f,11,f1,81,51,9e,a5,70, 12,6558), // Dinosaur
    CC(3c,42,81,87,89,90,50,38, 14,8818), // Moon Spirit
    CC(78,86,87,87,83,8f,46,38, 25,7684), // Gangster
    CC(70,8c,82,8f,81,8e,44,38, 25,3877), // Fire Sprite
    CC(41,e2,ae,d1,91,d1,91,6e, 32,8683), // Tank
    CC(70,88,89,8f,88,70,a8,f8, 15,7774), // Submarine

    CC(7e,83,8b,83,87,4f,3f,1e, 15,5975), // Triclops
    CC(78,84,82,41,41,b1,2e,40, 14,6596), // Alien
    CC(0e,11,71,91,b1,a2,85,7b, 12,9764), // Dragonet
    CC(de,b1,e1,f1,b1,9e,90,f8, 12,7595), // Sphynx
    CC(40,4e,51,51,d1,b1,8e,78, 22,4859), // Fencer
    CC(0f,71,86,81,86,81,76,0f, 25,9918), // Wood Nymph
    CC(6e,91,b1,f1,91,be,8c,70, 12,7695), // Boxer
    CC(e3,bc,e2,a2,e2,a2,fc,e3, 23,4896), // Robot
    CC(7e,91,81,a1,b1,bf,9e,60, 12,9459), // Lamia
    CC(70,88,8c,8a,89,74,24,12, 15,5769), // Meteor

    CC(c0,ae,71,91,91,71,ae,c0, 22,A675), // Harpy
    CC(3e,63,e3,e3,e3,e7,ff,3e, 13,486A), // Ninja
    CC(3e,71,d1,d1,f1,61,21,1e, 22,4A95), // Huntsman
    CC(71,89,87,87,87,8f,8d,71, 25,A693), // Professor
    CC(08,7c,8e,8e,8f,8f,7d,08, 25,74A8), // Witch
    CC(75,8f,88,8c,8c,98,ff,75, 15,AA81), // Hermes
    CC(0f,79,8a,89,8a,89,7a,0f, 25,A92A), // King
    CC(70,8e,89,89,8a,9d,72,3c, 15,9A5A), // The Pope
    CC(7e,8f,85,88,88,85,7f,3e, 25,A5AA), // Demon
    CC(02,75,8d,85,85,8d,75,02, 25,AAAA), // Angel
};

PROGMEM const char CARD_NAME_000[] = "Missing No";
PROGMEM const char CARD_NAME_001[] = "Fire Ant";
PROGMEM const char CARD_NAME_002[] = "Mushroom";
PROGMEM const char CARD_NAME_003[] = "Goo Monster";
PROGMEM const char CARD_NAME_004[] = "Bunny Rabbit";
PROGMEM const char CARD_NAME_005[] = "Butterfly";
PROGMEM const char CARD_NAME_006[] = "Dormouse";
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

PROGMEM const char CARD_FLAVOR_000[] = "FLAVOR";
PROGMEM const char CARD_FLAVOR_001[] = "NASTY, BITEY, ANNOYING IN LARGE NUMBERS";
PROGMEM const char CARD_FLAVOR_002[] = "THE BRIGHT RED ONES ARE POISONOUS, THIS ONE IS GREEN";
PROGMEM const char CARD_FLAVOR_003[] = "SLIGHTLY TACKY, USELESS AS AN ADHESIVE";
PROGMEM const char CARD_FLAVOR_004[] = "NO FEROCIOUS TEETH, NONE AT ALL";
PROGMEM const char CARD_FLAVOR_005[] = "FLOATS, DOESN'T STING";
PROGMEM const char CARD_FLAVOR_006[] = "DOESN'T ACTUALLY LIVE IN A TEAPOT";
PROGMEM const char CARD_FLAVOR_007[] = "JIGGLY AND SICKLY SWEET";
PROGMEM const char CARD_FLAVOR_008[] = "BEAUTIFUL FROM A DISTANCE, ALSO UP CLOSE";
PROGMEM const char CARD_FLAVOR_009[] = "MADE OF WAX, DO NOT EAT";
PROGMEM const char CARD_FLAVOR_010[] = "THE POLLEN CAUSES MORE THAN JUST ALLERGIES";
PROGMEM const char CARD_FLAVOR_011[] = "HURTS WHEN DROPPED FROM ANY HEIGHT";
PROGMEM const char CARD_FLAVOR_012[] = "STINGS, DOESN'T FLOAT";
PROGMEM const char CARD_FLAVOR_013[] = "";
PROGMEM const char CARD_FLAVOR_014[] = "";
PROGMEM const char CARD_FLAVOR_015[] = "";
PROGMEM const char CARD_FLAVOR_016[] = "";
PROGMEM const char CARD_FLAVOR_017[] = "";
PROGMEM const char CARD_FLAVOR_018[] = "";
PROGMEM const char CARD_FLAVOR_019[] = "";
PROGMEM const char CARD_FLAVOR_020[] = "";
PROGMEM const char CARD_FLAVOR_021[] = "";
PROGMEM const char CARD_FLAVOR_022[] = "";
PROGMEM const char CARD_FLAVOR_023[] = "";
PROGMEM const char CARD_FLAVOR_024[] = "";
PROGMEM const char CARD_FLAVOR_025[] = "";
PROGMEM const char CARD_FLAVOR_026[] = "";
PROGMEM const char CARD_FLAVOR_027[] = "";
PROGMEM const char CARD_FLAVOR_028[] = "";
PROGMEM const char CARD_FLAVOR_029[] = "";
PROGMEM const char CARD_FLAVOR_030[] = "";
PROGMEM const char CARD_FLAVOR_031[] = "";
PROGMEM const char CARD_FLAVOR_032[] = "";
PROGMEM const char CARD_FLAVOR_033[] = "";
PROGMEM const char CARD_FLAVOR_034[] = "";
PROGMEM const char CARD_FLAVOR_035[] = "";
PROGMEM const char CARD_FLAVOR_036[] = "";
PROGMEM const char CARD_FLAVOR_037[] = "";
PROGMEM const char CARD_FLAVOR_038[] = "";
PROGMEM const char CARD_FLAVOR_039[] = "";
PROGMEM const char CARD_FLAVOR_040[] = "";
PROGMEM const char CARD_FLAVOR_041[] = "";
PROGMEM const char CARD_FLAVOR_042[] = "";
PROGMEM const char CARD_FLAVOR_043[] = "";
PROGMEM const char CARD_FLAVOR_044[] = "";
PROGMEM const char CARD_FLAVOR_045[] = "";
PROGMEM const char CARD_FLAVOR_046[] = "";
PROGMEM const char CARD_FLAVOR_047[] = "";
PROGMEM const char CARD_FLAVOR_048[] = "";
PROGMEM const char CARD_FLAVOR_049[] = "";
PROGMEM const char CARD_FLAVOR_050[] = "";
PROGMEM const char CARD_FLAVOR_051[] = "";
PROGMEM const char CARD_FLAVOR_052[] = "";
PROGMEM const char CARD_FLAVOR_053[] = "";
PROGMEM const char CARD_FLAVOR_054[] = "";
PROGMEM const char CARD_FLAVOR_055[] = "";
PROGMEM const char CARD_FLAVOR_056[] = "";
PROGMEM const char CARD_FLAVOR_057[] = "";
PROGMEM const char CARD_FLAVOR_058[] = "";
PROGMEM const char CARD_FLAVOR_059[] = "";
PROGMEM const char CARD_FLAVOR_060[] = "";
PROGMEM const char CARD_FLAVOR_061[] = "";
PROGMEM const char CARD_FLAVOR_062[] = "";
PROGMEM const char CARD_FLAVOR_063[] = "";
PROGMEM const char CARD_FLAVOR_064[] = "";
PROGMEM const char CARD_FLAVOR_065[] = "";
PROGMEM const char CARD_FLAVOR_066[] = "";
PROGMEM const char CARD_FLAVOR_067[] = "";
PROGMEM const char CARD_FLAVOR_068[] = "";
PROGMEM const char CARD_FLAVOR_069[] = "";
PROGMEM const char CARD_FLAVOR_070[] = "";
PROGMEM const char CARD_FLAVOR_071[] = "";
PROGMEM const char CARD_FLAVOR_072[] = "";
PROGMEM const char CARD_FLAVOR_073[] = "";
PROGMEM const char CARD_FLAVOR_074[] = "";
PROGMEM const char CARD_FLAVOR_075[] = "";
PROGMEM const char CARD_FLAVOR_076[] = "";
PROGMEM const char CARD_FLAVOR_077[] = "";
PROGMEM const char CARD_FLAVOR_078[] = "";
PROGMEM const char CARD_FLAVOR_079[] = "";
PROGMEM const char CARD_FLAVOR_080[] = "";
PROGMEM const char CARD_FLAVOR_081[] = "";
PROGMEM const char CARD_FLAVOR_082[] = "";
PROGMEM const char CARD_FLAVOR_083[] = "";
PROGMEM const char CARD_FLAVOR_084[] = "";
PROGMEM const char CARD_FLAVOR_085[] = "";
PROGMEM const char CARD_FLAVOR_086[] = "";
PROGMEM const char CARD_FLAVOR_087[] = "";
PROGMEM const char CARD_FLAVOR_088[] = "";
PROGMEM const char CARD_FLAVOR_089[] = "";
PROGMEM const char CARD_FLAVOR_090[] = "";
PROGMEM const char CARD_FLAVOR_091[] = "";
PROGMEM const char CARD_FLAVOR_092[] = "";
PROGMEM const char CARD_FLAVOR_093[] = "";
PROGMEM const char CARD_FLAVOR_094[] = "";
PROGMEM const char CARD_FLAVOR_095[] = "";
PROGMEM const char CARD_FLAVOR_096[] = "";
PROGMEM const char CARD_FLAVOR_097[] = "";
PROGMEM const char CARD_FLAVOR_098[] = "";
PROGMEM const char CARD_FLAVOR_099[] = "";
PROGMEM const char CARD_FLAVOR_100[] = "";

#define CF(n) \
    CARD_FLAVOR_##n##0,CARD_FLAVOR_##n##1,CARD_FLAVOR_##n##2,CARD_FLAVOR_##n##3,CARD_FLAVOR_##n##4, \
    CARD_FLAVOR_##n##5,CARD_FLAVOR_##n##6,CARD_FLAVOR_##n##7,CARD_FLAVOR_##n##8,CARD_FLAVOR_##n##9

PROGMEM char *const CARD_FLAVORS [] = {
    CF(00), CF(01), CF(02), CF(03), CF(04), CF(05), CF(06), CF(07), CF(08), CF(09),
    CARD_FLAVOR_100,
};
