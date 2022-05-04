/*
** EPITECH PROJECT, 2022
** minishell_1
** File description:
** get_input
*/

#include <stdio.h>
#include <stdlib.h>
#include "minif.h"
#include "lib.h"

char *get_input(void)
{
    size_t size = 0;
    char *string = NULL;

    while (getline(&string, &size, stdin) == -1) {
        minif("exit\n");
        exit(0);
    }
    string[my_strlen(string) - 1] = '\0';
    return string;
}
