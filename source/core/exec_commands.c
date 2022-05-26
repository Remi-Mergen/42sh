/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** exec_commands
*/

#include "lib.h"
#include "minif.h"
#include "struct.h"
#include <unistd.h>
#include <stdlib.h>
void close_dup(int *tube, int fd);
void hello_pipe(mysh_t *mysh, command_t *command);
void exec_builtin(mysh_t *mysh, command_t *command);
void execution_command(mysh_t *mysh, command_t *command);

static void no_pipe(mysh_t *mysh, command_t *command)
{
    int std[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};
    if (command->redirect_stdout != 1) {
        close(1);
        dup2(command->redirect_stdout, 1);
        close(command->redirect_stdout);
    }
    execution_command(mysh, command);
    close_dup(std, 0);
    close_dup(std, 1);
}

static void is_there_a_pipe(mysh_t *mysh, command_t *command)
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
    if(mysh->exit != -1 && mysh->last_return_value == 0)
        exit(mysh->exit);
    return mysh->last_return_value;
}
