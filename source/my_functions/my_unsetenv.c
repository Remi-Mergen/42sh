/*
** EPITECH PROJECT, 2022
** minishell_1
** File description:
** unsetenv
*/

#include "minif.h"
#include "prototype.h"
#include "struct.h"
#include "lib.h"
#include "my_cmd.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void remove_in_env(mysh_t *mysh, command_t *command, int i)
{
    list_env_t *prev = NULL;

    for (list_env_t *tmp = mysh->env; tmp; prev = tmp, tmp = tmp->next) {
        if (my_strncmp(tmp->data, command->args[i],
                                        my_strlen(command->args[i])) == 0) {
            prev->next = tmp->next;
            free(tmp->data);
            free(tmp);
            return;
        }
    }
}

int my_unsetenv(mysh_t *mysh, command_t *command)
{
    if (command->args == NULL) {
        my_env(mysh, command);
        return 0;
    } else if (my_array_len(command->args) == 0) {
        minif("unsetenv: Too few arguments.\n");
        return 1;
    }
    for (int i = 0; command->args[i]; i++) {
        remove_in_env(mysh, command, i);
    }
    return 0;
}
