/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** redirect_left
*/

#include "lib.h"
#include "struct.h"
#include "define.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void handlerr(char *input, command_t **command, int i)
{
    int fd = STDIN_FILENO;
    char *to_open = my_strcpy(&input[i + 1]);

    for (; to_open[0] == ' '; to_open++);
    fd = open(to_open, O_RDONLY);
    if (fd == -1)
        perror("open");
    (*command)->redirect_stdin = fd;
}

void redirect_left_handler(char *input, UNUSED command_t **command)
{
    for (unsigned int i = 0; input[i]; ++i) {
        if (input[i] == '<') {
            handlerr(input, command, i);
            break;
        }
    }
}
