/*
** EPITECH PROJECT, 2022
** minishell_1
** File description:
** env
*/

#include "minif.h"
#include "struct.h"
#include "define.h"

int my_env(mysh_t *mysh, UNUSED command_t *command)
{
    for (list_env_t *tmp = mysh->env; tmp; tmp = tmp->next)
        minif("%s\n", tmp->data);
    return 0;
}
