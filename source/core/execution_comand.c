/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** execution_comand
*/

#include "lib.h"
#include "minif.h"
#include "struct.h"
#include <unistd.h>

void execution_command(mysh_t *mysh, command_t *command)
{
    int pid = 1;
    if (command->builtin != NULL) {
        command->builtin->fct_ptr(mysh, command);
        return;
    } else if (command->return_value == -1) {
        minif("%s: Command not found.\n", command->path);
        mysh->last_return_value = 1;
        return;
    }
    pid = fork();
    if (pid == 0) {
        execve(command->path, command->args, command->env);
    } else {
        mysh->last_return_value = my_wait(&pid);
    }
}
