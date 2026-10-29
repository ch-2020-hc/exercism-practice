#include "resistor_color_trio.h"
#include "string.h"

resistor_value_t color_code(resistor_band_t* colors)
{
    resistor_value_t R; 
    long long power = 1;
    for (resistor_band_t i = 0; i < colors[2]; ++i)
    {
        power *= 10;
    }
    
    R.value = (colors[0]*10 + colors[1]) * power; 

    if (power < 1000 && R.value < 1000)
    {
        R.unit = OHMS;
    }
    else if ((power >= 1000 && power < 1000000 ) || (R.value >= 1000 && R.value < 1000000 ))
    {
        R.unit = KILOOHMS;
        R.value /= 1000;
    }
    else if ((power >= 1000000 && power < 1000000000 ) || (R.value >= 1000000 && R.value < 1000000000))
    {
        R.unit = MEGAOHMS;
        R.value /= 1000000;        
    }
    else
    {
        R.unit = GIGAOHMS;
        R.value /= 1000000000;        
    }
    return R;
}
