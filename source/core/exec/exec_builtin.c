/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** exec_builtin
*/

#include "struct.h"

void exec_builtin(mysh_t *mysh, command_t *command)
{
    mysh->last_return_value = command->builtin->fct_ptr(mysh, command);
}
