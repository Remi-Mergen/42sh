/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** exec_commands
*/

#include "lib.h"
#include "struct.h"
#include <unistd.h>
#include <stdlib.h>

int exec_commands(mysh_t *mysh)
{
    int pid = 0;
    int status = 0;

    for (list_commands_t *tmp = mysh->commands_list; tmp; tmp = tmp->next) {
        pid = fork();
        if (pid == 0) {
            execve(tmp->command->path, tmp->command->args, tmp->command->env);
            exit(0);
        } else {
            status = my_wait(&pid);
        }
    }
    return status;
}
