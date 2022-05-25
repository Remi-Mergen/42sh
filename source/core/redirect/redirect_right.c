/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** redirect_right
*/

#include "struct.h"
#include "define.h"
#include <unistd.h>

void redirect_right_handler(char *input, command_t **command,
                                                        UNUSED mysh_t **mysh)
{
    for (unsigned int i = 0; input[i]; ++i) {
        if (input[i] == '>') {
            int fd[2];
            pipe(fd);
            close(fd[0]);
            (*command)->redirect_stdout = fd[1];
            break;
        }
    }
}
