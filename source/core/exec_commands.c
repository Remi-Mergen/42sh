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

static void pipe_execution(mysh_t *mysh, command_t *command)
{
    int fd[2];
    int pid = 0x0;

    pipe(fd);
    pid = fork();
    if (pid == 0) {
        dup2(fd[1], 1);
        close(fd[0]);
        execve(command->path, command->args, command->env);
        exit(0);
    } else {
        close(fd[1]);
        dup2(fd[0], 0);
        mysh->last_return_value = my_wait(&pid);
    }
}
/*
for (command_t *tmp_pipe = tmp->command; tmp_pipe; tmp_pipe = tmp_pipe->next_pipe) {
    if (tmp_pipe->builtin == NULL) {
        not_builtin(mysh, tmp_pipe);
    } else {
        exec_builtin(mysh, tmp_pipe);
    }
}*/

int exec_commands(mysh_t *mysh)
{
    for (list_commands_t *tmp = mysh->commands_list; tmp; tmp = tmp->next) {
        if (tmp->command->next_pipe != NULL) {
            pipe_execution(mysh, tmp->command);
        } else {
            if (tmp->command->builtin == NULL) {
                not_builtin(mysh, tmp->command);
            } else {
                exec_builtin(mysh, tmp->command);
            }
        }
    }
    return mysh->last_return_value;
}
