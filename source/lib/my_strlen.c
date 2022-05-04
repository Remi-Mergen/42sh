/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** return lenght of a string
*/

#include <stddef.h>

size_t my_strlen(const char *s)
{
    size_t len = 0;

    for(;;) {
        unsigned x = *(unsigned*)s;
        if( (x & 0xFF) == 0)
            return len;
        if( (x & 0xFF00) == 0)
            return len + 1;
        if( (x & 0xFF0000) == 0)
            return len + 2;
        if( (x & 0xFF000000) == 0)
            return len + 3;
        s += 4;
        len += 4;
    }
}
