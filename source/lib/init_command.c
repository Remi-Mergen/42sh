/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** init_command
*/

#include "struct.h"
#include <stddef.h>
#include <unistd.h>

void init_command(command_t **command, char **env)
{
    (*command)->env = env;
    (*command)->builtin = NULL;
    (*command)->path = NULL;
    (*command)->output = NULL;
    (*command)->args = NULL;
    (*command)->return_value = 0;
    (*command)->prev_pipe = NULL;
    (*command)->next_pipe = NULL;
    (*command)->redirect_stdout = STDOUT_FILENO;
    (*command)->redirect_stdin = STDIN_FILENO;
    (*command)->eof = 0;
    (*command)->heredoc = NULL;
}
