#pragma once

PROGMEM const uint8_t PRINTABLE_CHARS [] = {
    0x00, 0x00, 0x00, 0x00, 0x17, 0x00, 0x03, 0x00, 0x03, 0x1f, 0x0a, 0x1f, 0x16, 0x1f, 0x0a, // !"#$
    0x19, 0x04, 0x13, 0x1b, 0x15, 0x13, 0x00, 0x03, 0x00, 0x00, 0x0e, 0x11, 0x11, 0x0e, 0x00, //%&'()
    0x15, 0x0e, 0x15, 0x04, 0x0e, 0x04, 0x00, 0x18, 0x00, 0x04, 0x04, 0x04, 0x00, 0x10, 0x00, //*+,-.
    0x10, 0x0e, 0x01, 0x1f, 0x11, 0x1f, 0x12, 0x1f, 0x10, 0x19, 0x15, 0x12, 0x11, 0x15, 0x0a, ///0123
    0x07, 0x04, 0x1f, 0x13, 0x15, 0x09, 0x1e, 0x15, 0x1d, 0x01, 0x19, 0x07, 0x1f, 0x15, 0x1f, //45678
    0x17, 0x15, 0x0f, 0x00, 0x0a, 0x00, 0x00, 0x1a, 0x00, 0x04, 0x0a, 0x11, 0x0a, 0x0a, 0x0a, //9:;<=
    0x11, 0x0a, 0x04, 0x01, 0x15, 0x02, 0x0e, 0x11, 0x16, 0x1e, 0x05, 0x1e, 0x1f, 0x15, 0x0a, //>?@AB
    0x0e, 0x11, 0x11, 0x1f, 0x11, 0x0e, 0x1f, 0x15, 0x11, 0x1f, 0x05, 0x01, 0x0e, 0x11, 0x1d, //CDEFG
    0x1f, 0x04, 0x1f, 0x11, 0x1f, 0x11, 0x08, 0x11, 0x0f, 0x1f, 0x04, 0x1b, 0x1f, 0x10, 0x10, //HIJKL
    0x1f, 0x07, 0x1f, 0x1f, 0x01, 0x1e, 0x0e, 0x11, 0x0e, 0x1f, 0x05, 0x02, 0x0e, 0x19, 0x16, //MNOPQ
    0x1f, 0x05, 0x1a, 0x12, 0x15, 0x09, 0x01, 0x1f, 0x01, 0x0f, 0x10, 0x1f, 0x07, 0x18, 0x07, //RSTUV
    0x1f, 0x18, 0x1f, 0x1b, 0x04, 0x1b, 0x03, 0x1c, 0x03, 0x19, 0x15, 0x13, 0x00, 0x1f, 0x11, //WXYZ[
    0x01, 0x0e, 0x10, 0x11, 0x1f, 0x00, 0x02, 0x01, 0x02, 0x10, 0x10, 0x10, 0x01, 0x02, 0x00, //\]^_`
    0x0c, 0x12, 0x1c, 0x1f, 0x12, 0x0c, 0x0c, 0x12, 0x12, 0x0c, 0x12, 0x1f, 0x0c, 0x12, 0x14, //abcde
    0x1e, 0x09, 0x02, 0x16, 0x1a, 0x0c, 0x1f, 0x04, 0x18, 0x14, 0x1d, 0x10, 0x10, 0x1d, 0x00, //fghij
    0x1f, 0x08, 0x16, 0x11, 0x1f, 0x10, 0x1e, 0x0e, 0x1c, 0x1e, 0x02, 0x1c, 0x0c, 0x12, 0x0c, //klmno
    0x1e, 0x0a, 0x04, 0x04, 0x0a, 0x1e, 0x1c, 0x02, 0x02, 0x14, 0x12, 0x0a, 0x02, 0x0f, 0x12, //pqrst
    0x0e, 0x10, 0x1e, 0x0e, 0x10, 0x0e, 0x1e, 0x18, 0x1e, 0x12, 0x0c, 0x12, 0x12, 0x14, 0x0e, //uvwxy
    0x1a, 0x12, 0x16, 0x04, 0x1b, 0x11, 0x00, 0x1f, 0x00, 0x11, 0x1b, 0x04, 0x0c, 0x04, 0x06, //z{|}~

};

PROGMEM const uint8_t PRINTABLE_CHARS_LARGE [] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5f, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, // !"
    0x14, 0x7f, 0x14, 0x7f, 0x14, 0x24, 0x2a, 0x6b, 0x2a, 0x12, 0x43, 0x33, 0x08, 0x66, 0x61, //#$%
    0x36, 0x49, 0x59, 0x26, 0x50, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0x00, //&'(
    0x00, 0x41, 0x3e, 0x00, 0x00, 0x2a, 0x1c, 0x3e, 0x1c, 0x2a, 0x08, 0x08, 0x3e, 0x08, 0x08, //)*+
    0x00, 0x80, 0x40, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00, 0x40, 0x00, 0x00, //,-.
    0x00, 0x60, 0x1c, 0x03, 0x00, 0x3e, 0x51, 0x49, 0x45, 0x3e, 0x40, 0x42, 0x7f, 0x40, 0x40, ///01
    0x62, 0x51, 0x49, 0x49, 0x46, 0x22, 0x41, 0x49, 0x49, 0x36, 0x1c, 0x12, 0x11, 0x7f, 0x10, //234
    0x27, 0x49, 0x49, 0x49, 0x31, 0x3c, 0x4a, 0x49, 0x49, 0x30, 0x01, 0x01, 0x71, 0x0d, 0x03, //567
    0x36, 0x49, 0x49, 0x49, 0x36, 0x06, 0x49, 0x49, 0x29, 0x1e, 0x00, 0x00, 0x48, 0x00, 0x00, //89:
    0x00, 0x80, 0x48, 0x00, 0x00, 0x00, 0x08, 0x14, 0x22, 0x00, 0x00, 0x14, 0x14, 0x14, 0x00, //;<=
    0x00, 0x22, 0x14, 0x08, 0x00, 0x02, 0x01, 0x51, 0x09, 0x06, 0x3e, 0x41, 0x5d, 0x49, 0x2e, //>?@
    0x7e, 0x09, 0x09, 0x09, 0x7e, 0x7f, 0x49, 0x49, 0x49, 0x36, 0x3e, 0x41, 0x41, 0x41, 0x22, //ABC
    0x7f, 0x41, 0x41, 0x41, 0x3e, 0x7f, 0x49, 0x49, 0x49, 0x41, 0x7f, 0x09, 0x09, 0x09, 0x01, //DEF
    0x3e, 0x41, 0x41, 0x49, 0x3a, 0x7f, 0x08, 0x08, 0x08, 0x7f, 0x41, 0x41, 0x7f, 0x41, 0x41, //GHI
    0x30, 0x40, 0x41, 0x41, 0x3f, 0x7f, 0x08, 0x14, 0x22, 0x41, 0x7f, 0x40, 0x40, 0x40, 0x40, //JKL
    0x7f, 0x02, 0x0c, 0x02, 0x7f, 0x7f, 0x02, 0x04, 0x08, 0x7f, 0x3e, 0x41, 0x41, 0x41, 0x3e, //MNO
    0x7f, 0x11, 0x11, 0x11, 0x0e, 0x3e, 0x41, 0x51, 0x21, 0x5e, 0x7f, 0x09, 0x19, 0x29, 0x46, //PQR
    0x26, 0x49, 0x49, 0x49, 0x32, 0x01, 0x01, 0x7f, 0x01, 0x01, 0x3f, 0x40, 0x40, 0x40, 0x3f, //STU
    0x07, 0x38, 0x40, 0x38, 0x07, 0x7f, 0x20, 0x1c, 0x20, 0x7f, 0x63, 0x14, 0x08, 0x14, 0x63, //VWX
    0x03, 0x04, 0x78, 0x04, 0x03, 0x61, 0x51, 0x49, 0x45, 0x43, 0x00, 0x00, 0x7f, 0x41, 0x00, //YZ[
    0x00, 0x03, 0x1c, 0x60, 0x00, 0x00, 0x41, 0x7f, 0x00, 0x00, 0x18, 0x06, 0x01, 0x06, 0x18, //\]^
    0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x01, 0x02, 0x00, 0x00, 0x38, 0x44, 0x44, 0x24, 0x78, //_`a
    0x7f, 0x44, 0x44, 0x44, 0x38, 0x38, 0x44, 0x44, 0x44, 0x20, 0x38, 0x44, 0x44, 0x44, 0x7f, //bcd
    0x38, 0x54, 0x54, 0x54, 0x08, 0x08, 0x7e, 0x09, 0x09, 0x02, 0x18, 0xa4, 0xa4, 0xa4, 0x78, //efg
    0x7f, 0x04, 0x04, 0x04, 0x78, 0x40, 0x44, 0x7d, 0x40, 0x40, 0x40, 0x84, 0x85, 0x7c, 0x00, //hij
    0x7f, 0x10, 0x28, 0x44, 0x00, 0x40, 0x41, 0x7f, 0x40, 0x40, 0x7c, 0x04, 0x78, 0x04, 0x78, //klm
    0x7c, 0x08, 0x04, 0x04, 0x78, 0x38, 0x44, 0x44, 0x44, 0x38, 0xfc, 0x24, 0x24, 0x24, 0x18, //nop
    0x18, 0x24, 0x24, 0x24, 0xfc, 0x7c, 0x08, 0x04, 0x04, 0x08, 0x48, 0x54, 0x54, 0x54, 0x24, //qrs
    0x04, 0x3f, 0x44, 0x44, 0x20, 0x3c, 0x40, 0x40, 0x20, 0x7c, 0x1c, 0x20, 0x40, 0x20, 0x1c, //tuv
    0x3c, 0x40, 0x30, 0x40, 0x3c, 0x44, 0x28, 0x10, 0x28, 0x44, 0x9c, 0xa0, 0xa0, 0x40, 0x3c, //wxy
    0x64, 0x54, 0x54, 0x54, 0x4c, 0x00, 0x08, 0x77, 0x41, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, //z{|
    0x00, 0x41, 0x77, 0x08, 0x00, 0x18, 0x04, 0x08, 0x10, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, //}~

};