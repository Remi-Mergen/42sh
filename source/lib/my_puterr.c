/*
** EPITECH PROJECT, 2022
** minishell_1 [WSL: Ubuntu]
** File description:
** my_puterr
*/

#include <unistd.h>
#include "lib.h"

void my_puterr(char *s)
{
    write(2, s, my_strlen(s));
}
