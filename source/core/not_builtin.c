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
    //TODO builtin gestion
    int pid = fork();
    if (pid == 0) {
        execve(command->path, command->args, command->env);
    } else {
        mysh->last_return_value = my_wait(&pid);
    }
}

/* void pip_execution(mysh_t *mysh, command_t *command)
{
    int tube[2];
    pipe(tube);
    close_dup(tube, STDOUT_FILENO);
    execution_command(mysh, command);
    close_dup(tube, STDIN_FILENO);

    int tube2[2];
    pipe(tube2);
    close_dup(tube2, STDOUT_FILENO);
    execution_command(mysh, command->next_pipe);
    close_dup(tube2, STDIN_FILENO);


} */

unsigned int count_pipe(command_t *command)
{
    unsigned int count = 0;
    for (; command != NULL; command = command->next_pipe, ++count);
    return count;
}

void hello_pipe(mysh_t *mysh, command_t *command)
{
    int std[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};
    unsigned int pipe_count = count_pipe(command);
    int tube[pipe_count][2];

    for (unsigned int i = 0; i < pipe_count - 1;
                                        i++, command = command->next_pipe) {
        pipe(tube[i]) != -1 ? 0 : perror("pipe");
        close_dup(tube[i], STDOUT_FILENO);
        execution_command(mysh, command);
        close_dup(tube[i], STDIN_FILENO);
    }
    close_dup(std, 1);
    execution_command(mysh, command->next_pipe);
    close_dup(std, 0);
}
