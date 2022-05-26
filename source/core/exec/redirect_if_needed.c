/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** redirect_if_needed
*/

#include "struct.h"
#include <unistd.h>

void redirect_stdin(command_t *command)
{
    if (command->redirect_stdin != 0) {
        close(0);
        dup2(command->redirect_stdin, 0);
        close(command->redirect_stdin);
    }
}

void redirect_stdout(command_t *command)
{
    if (command->redirect_stdout != 1) {
        close(1);
        dup2(command->redirect_stdout, 1);
        close(command->redirect_stdout);
    }
}
