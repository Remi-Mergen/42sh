/*
** EPITECH PROJECT, 2022
** minishell_1
** File description:
** get_first_word
*/

#include <stdlib.h>

char *get_first_word(char *line, char separator)
{
    char *str = malloc(sizeof(char) * 100);

    for (unsigned int i = 0; i < 100; i++)
        str[i] = '\0';
    for (unsigned int i = 0; line[i] != separator; ++i)
        str[i] = line[i];
    return str;
}
