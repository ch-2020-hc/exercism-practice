#include "allergies.h"
allergen_list_t get_allergens(int value)
{
    allergen_list_t a_list;
    a_list.count = 0;
    // init allergens to false;
    for (int i = 0; i < 8; ++i)
    {
        a_list.allergens[i] = false;
    }
    int power = 0;
    
    if(value >= 256)
    {
        value -= 256;
    }
    for (power = 0 ; value >= 1; power++)
    {
        if (value % 2 != 0)
        {
            a_list.count++;
            a_list.allergens[power] = true;
        }
        value /= 2;
    } 
    return a_list;
}
bool is_allergic_to(allergen_t allergen, int value)
{    
    return get_allergens(value).allergens[allergen];
}