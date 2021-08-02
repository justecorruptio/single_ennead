# TERM TWIRL

This is a clone of Text Twist for Arduboy. There are over 1600 different levels.

## Controls
- Left/Right: Move the cursor.
- Up: Select a letter.
- Down: Retract a letter.
- A: Play the word.
- B: Retract all the letters. If they already are, then shuffle the letters.

## Compilation
All of the needed files are checked in to compile and upload via Arduino.

You can also tweak and rebuild the compressed dictionary with:
`. config.sh`

## Internals
We first find the most common 6-letter English words via a corpus. Based on that, look for all possible valid words
that *can* show up in a game with these 6-letter words as the target. Compress the resulting set of words into a DAWG.

Since we do not have 2^16 nodes (2^13 covers us), we have 4 wasted bits of storage every 3 bytes. (17% waste)

When loading a new level, the DAWG is traversed once to pick a random 6-letter word, and then again to find all the
words that are subanagrams of that 6-letter word.

## Sources
- Word Frequencies: Peter Norvig's [Natural Language Corpus](https://norvig.com/ngrams/)
- Word List: [Tournament Word List](https://en.wikipedia.org/wiki/NASPA_Word_List) for North American Scrabble players.
- DAWG Compressor: [DAWG generator](https://github.com/AndrasKovacs/dawg-gen) for Andras Kovacs. 
