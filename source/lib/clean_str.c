/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** clean_str
*/

#include <stdlib.h>

char *clear_str(char *str)
{
    int i = 0;
    int a = 0;
    int b = 0;
    int already_in_space = 0;
    int count = 0;
    for (;str[0] == ' ' || str[0] == '\t'; str++);
    for (; str[i]; i++)
        if (str[i] != ' ' || str[i] != '\t')
            count++;
    char *new = malloc(sizeof(char) * (count + 1));
    for (i = 0; str[a]; a++) {
        if (str[a] == ' ' && already_in_space == 0) {
            new[b++] = str[a];
            already_in_space = 1;
            continue;
        }
        if (str[a] == '\t') {
            if (already_in_space == 0)
                new[b++] = ' ';
            already_in_space = 1;
            continue;
        }
        if (str[a] != ' ' && str[a] != '\t') {
            new[b++] = str[a];
            already_in_space = 0;
            continue;
        }
    }
    return new;
}
