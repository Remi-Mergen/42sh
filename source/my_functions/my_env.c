/*
** EPITECH PROJECT, 2022
** minishell_1
** File description:
** env
*/

#include "minif.h"
#include "struct.h"

int my_env(mysh_t *mysh)
{
    for (int i = 0; mysh->env[i]; i++)
        minif("%s\n", mysh->env[i]);
    return 0;
}
