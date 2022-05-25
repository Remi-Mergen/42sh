/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** not_builtin
*/

#include "lib.h"
#include "struct.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //TODO to remove
void close_dup(int *tube, int fd);

void execution_command(mysh_t *mysh, command_t *command)
{
    if (command->builtin != NULL) {
        command->builtin->fct_ptr(mysh, command);
        return;
    }
    int pid = fork();
    if (pid == 0) {
        execve(command->path, command->args, command->env);
    } else {
        mysh->last_return_value = my_wait(&pid);
    }
}

unsigned int count_pipe(command_t *command)
{
    unsigned int count = 0;
    for (command_t *tmp = command; tmp != NULL; tmp = tmp->next_pipe, ++count);
    return count - 1;
}

void hello_pipe(mysh_t *mysh, command_t *command)
{
    int std[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};
    unsigned int pipe_count = count_pipe(command);
    int tube[pipe_count][2];

    for (unsigned int i = 0; i < pipe_count;
                                        i++, command = command->next_pipe) {
        if (pipe(tube[i]) == -1)
            perror("pipe");
        close_dup(tube[i], STDOUT_FILENO);
        execution_command(mysh, &(*command));
        close_dup(tube[i], STDIN_FILENO);
    }
    close_dup(std, 1);
    execution_command(mysh, command);
    close_dup(std, 0);
}
