/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_strcpy
*/

#include "lib.h"
#include <string.h>
#include <stdlib.h>

char *my_strcpy(const char *src)
{
    size_t len = strlen(src);
    char *dest = malloc(sizeof(char) * (len + 1));
    for (size_t i = 0; i < len; i++)
        dest[i] = src[i];
    dest[len] = '\0';
    return dest;
}
