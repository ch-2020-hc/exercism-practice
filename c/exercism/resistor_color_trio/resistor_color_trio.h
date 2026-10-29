#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

typedef enum {
    BLACK = 0,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
}resistor_band_t;

typedef enum {
    OHMS = 0,
    KILOOHMS,
    MEGAOHMS,
    GIGAOHMS
}resistor_unit;

typedef struct {
    long long value;
    resistor_unit unit;
}resistor_value_t;

resistor_value_t color_code(resistor_band_t colors[4]);

#endif
