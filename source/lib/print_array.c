/*
** EPITECH PROJECT, 2022
** minishell_1 [WSL: Ubuntu]
** File description:
** print_array
*/

#include <stdio.h>
#include "minif.h"

void print_array(char **array)
{
    for (unsigned int i = 0; array[i]; ++i)
        minif("%d: %s\n", i, array[i]);
}
