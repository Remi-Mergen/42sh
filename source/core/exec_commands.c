/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** exec_commands
*/

#include "lib.h"
#include "struct.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //TODO to remove

void not_builtin(mysh_t *mysh, command_t *command)
{
    int pid = fork();

    if (pid == 0) {
        execve(command->path, command->args, command->env);
        exit(0);
    } else {
        mysh->last_return_value = my_wait(&pid);
    }
}

void exec_builtin(mysh_t *mysh, command_t *command)
{
    mysh->last_return_value = command->builtin->fct_ptr(mysh, command);
}

int exec_commands(mysh_t *mysh)
{
    for (list_commands_t *tmp = mysh->commands_list; tmp; tmp = tmp->next) {
        if (tmp->command->builtin == NULL) {
            not_builtin(mysh, tmp->command);
        } else {
            exec_builtin(mysh, tmp->command);
        }
    }
    return mysh->last_return_value;
}
