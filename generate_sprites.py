from PIL import Image

def load_bands(fn):
    im = Image.open(fn)
    im = im.split()[-1]
    im = im.transpose(Image.TRANSPOSE)

    data = list(1 if x else 0 for x in im.getdata())
    stripes = []
    for i in xrange(0, 128 * 128, 8):
        v = 0
        for j in xrange(8):
            v |= data[i + j] << j
        stripes.append(v)

    bands = []
    for i in xrange(256 * 8):
        v = stripes[(i % 8) * 16 + ((i % 128) // 8) + (i // 128) * 128]
        bands.append(v)

    im.close()
    return bands

def get_char(bands, n, width):
    return ', '.join("0x%02x" % (bands[n * 8 + j],) for j in xrange(width))

def formatted(bands, width):
    s = ''
    for n in xrange(32, 128, 15 // width):
        s += '    '
        s += ', '.join(
            get_char(bands, n + i, width)
            for i in xrange(15 // width)
        )
        s += ', //'
        s += ''.join(
            chr(n + i)
            for i in xrange(15 // width)
            if n + i > 31 and n + 1 < 128
        )
        s += '\n'
    return s


fh = open("jay_sprites.h", 'w')
fh.write("""
#pragma once

PROGMEM const uint8_t PRINTABLE_CHARS [] = {
%s
};

PROGMEM const uint8_t PRINTABLE_CHARS_LARGE [] = {
%s
};
""".strip() % (
    formatted(load_bands("assets/font_small.png"), 3),
    formatted(load_bands("assets/font_large.png"), 5),
))
