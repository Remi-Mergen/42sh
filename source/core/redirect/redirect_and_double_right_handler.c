/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** redirect_right
*/

#include "lib.h"
#include "struct.h"
#include "define.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void handler(char *input, command_t **command, int i)
{
    int fd = STDOUT_FILENO;
    char *to_open = my_strcpy(&input[i + 1]);

    for (; to_open[0] == ' '; ++to_open);
    if (to_open[0] == '>') {
        to_open++;
        for (; to_open[0] == ' '; ++to_open);
        fd = open(to_open, O_CREAT | O_APPEND | O_RDWR, 00644);
    } else
        fd = open(to_open, O_CREAT | O_TRUNC | O_RDWR, 00644);
    if (fd == -1)
        perror("open");
    (*command)->redirect_stdout = fd;
}

static int error_handling(mysh_t *mysh, const char *input, command_t *command)
{
    int count = 0;

    for (unsigned int x = 0; input[x] != '\0'; x++) {
        if (input[x] == '>') {
            ++count;
            ++x;
        } else if (input[x] == '|' && count != 0) {
            write(2, "Ambiguous output redirect.\n", 27);
            command->return_value = -2;
            mysh->last_return_value = 1;
            return -1;
        }
    }
    if (count > 1) {
        write(2, "Ambiguous output redirect.\n", 27);
        command->return_value = -2;
        mysh->last_return_value = 1;
        return -1;
    }
    return 0;
}

void redirect_and_double_right_handler(mysh_t *mysh, char *input,
                                                        command_t **command)
{
    if (error_handling(mysh, input, (*command)) == -1)
        return;
    for (unsigned int i = 0; input[i]; ++i) {
        if (input[i] == '>') {
            handler(input, command, i);
            break;
        }
    }
}
