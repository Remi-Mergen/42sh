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
void exec_builtin(mysh_t *mysh, command_t *command);
void hello_pipe(mysh_t *mysh, command_t *command);

void execution_command(mysh_t *mysh, command_t *command)
{
    int pid = 1;
    if (command->builtin != NULL) {
        command->builtin->fct_ptr(mysh, command);
        return;
    } else if (command->return_value == -1) {
        minif("%s: Command not found.\n", command->path);
        mysh->last_return_value = 1;
        return;
    }
    pid = fork();
    if (pid == 0) {
        execve(command->path, command->args, command->env);
    } else {
        mysh->last_return_value = my_wait(&pid);
    }
}

static void no_pipe(mysh_t *mysh, command_t *command)
{
    execution_command(mysh, command);
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
