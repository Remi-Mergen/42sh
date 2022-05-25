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
void exec_builtin(mysh_t *mysh, command_t *command);
void hello_pipe(mysh_t *mysh, command_t *command);
void execution_command(mysh_t *mysh, command_t *command);

void close_dup(int *tube, int fd)
{
    close(fd);
    dup2(tube[fd], fd);
    close(tube[fd]);
}

void no_pipe(mysh_t *mysh, command_t *command)
{
    execution_command(mysh, command);
}

void is_there_a_pipe(mysh_t *mysh, command_t *command)
{
    if (command->next_pipe != NULL) {
        hello_pipe(mysh, command);
    } else {
        no_pipe(mysh, command);
    }
}

int exec_commands(mysh_t *mysh)
{
    for (list_commands_t *tmp = mysh->commands_list; tmp; tmp = tmp->next) {
        if (tmp->command->builtin != NULL && tmp->command->next_pipe == NULL) {
            tmp->command->builtin->fct_ptr(mysh, tmp->command);
        } else {
            is_there_a_pipe(mysh, tmp->command);
        }
    }
    return mysh->last_return_value;
}
