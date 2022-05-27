/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** execution_one_comand
*/

#include "lib.h"
#include "minif.h"
#include "define.h"
#include "struct.h"
#include <unistd.h>
void close_dup(int *tube, int fd);

void execution_command(mysh_t *mysh, command_t *command)
{
    int pid = 1;
    if (command->builtin != NULL) {
        command->builtin->fct_ptr(mysh, command);
        return;
    } else if (command->return_value == -1) {
        write(2, command->path, my_strlen(command->path));
        write(2, ": Command not found.\n", 21);
        mysh->last_return_value = 1;
        return;
    } else if (command->return_value == -2)
        return;
    pid = fork();
    if (pid == 0) {
        execve(command->path, command->args, command->env);
    } else {
        mysh->last_return_value = my_wait(&pid);
    }
}
