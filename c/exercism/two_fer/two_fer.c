#include "two_fer.h"
#include "string.h"


void two_fer(char *buffer, const char *name)
{
    if (name == NULL  || strlen(name) == 0)
    {
        // buffer = "One for you, one for me."; => wrong method of copying string to buffer
        // Because buffer is just a copy of the address passed into the function, 
        // you aren't actually altering the memory that the caller provided. 
        // As soon as the function ends, that assignment is completely forgotten, 
        // and the caller is left with an empty or uninitialized string
        strcpy(buffer, "One for you, one for me.");
    }
    else
    {
        char *cpy = buffer;
        cpy = "One for x, one for me.";
        size_t len = strlen(cpy);
        size_t l_name = strlen(name);

        for (size_t i = 0; i < len; ++i)
        {
            if (cpy[i] == 'x')
            {
                for (size_t j = 0; j < l_name; ++j)
                {
                    int x = i+j;
                    buffer[x] = name[j];
                }
            }
            else if (cpy[i] == ',')
            {
                while (cpy[i] != '\0')
                {
                    buffer[i+l_name-1] = cpy[i];
                    i++;
                }
                buffer[i+l_name-1] = '\0';
                break;
            } 
            else buffer[i] = cpy[i];  
        }
        
    }
}
