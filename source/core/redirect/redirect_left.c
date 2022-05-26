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

void redirect_left_handler(char *input, UNUSED command_t **command,
                                                        UNUSED mysh_t **mysh)
{
    for (unsigned int i = 0; input[i]; ++i) {
        if (input[i] == '<')
            break;
    }
}

//TODO
/* 
static void handlerr(char *input, command_t **command, int i)
{
    int fd = STDOUT_FILENO;
    char *to_open = my_strcpy(&input[i + 1]);

    for (; to_open[0] == ' '; to_open++);
    if (input[i + 1] == '>')
        fd = open(to_open, O_CREAT | O_APPEND | O_RDWR, 00334);
    else
        fd = open(to_open, O_CREAT | O_TRUNC | O_RDWR, 00334);
    if (fd == -1)
        perror("open");
    (*command)->redirect_stdout = fd;
}

void redirect_and_double_right_handler(char *input, command_t **command)
{
    int count = 0;
    for (unsigned int x = 0; input[x] != '\0'; x++) {
        if (input[x] == '<') {
            count++;
            x++;
        }
    }
    if (count > 1) {
        write(2, "Ambiguous output redirect.\n", 27);
        return;
    }
    for (unsigned int i = 0; input[i]; ++i) {
        if (input[i] == '<') {
            handlerr(input, command, i);
            break;
        }
    }
}
 */
