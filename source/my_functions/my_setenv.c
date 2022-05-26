/*
** EPITECH PROJECT, 2022
** minishell_1
** File description:
** my_setenv
*/

#include "lib.h"
#include "my_cmd.h"
#include "minif.h"
#include "define.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

static int already_here(mysh_t *mysh, command_t *command, char *new_var)
{
    for (list_env_t *tmp = mysh->env; tmp; tmp = tmp->next) {
        if (my_strncmp(tmp->data, command->args[0], my_strlen(command->args[0])) == 0) {
            tmp->data = new_var;
            return 1;
        }
    }
    return 0;
}

static void add_var_in_env(mysh_t *mysh, char *new_var)
{
    list_env_t *new_env = malloc(sizeof(list_env_t));

    if (!new_env) {
        write(2, "Could not allocate memory\n", 26);
        return;
    }
    new_env->data = new_var;
    new_env->next = mysh->env;
    mysh->env = new_env;
}

int my_setenv(mysh_t *mysh, UNUSED command_t *command)
{
    char *new_var = my_strcat(my_strcat(my_strcat(command->args[1], "="),
                                                    command->args[2]), "\0");

    if (my_array_len(command->args) > 3) {
        write(2, "setenv: Too many arguments.\n", 28);
        return 1;
    } else if (my_array_len(command->args) == 1) {
        my_env(mysh, command);
        return 0;
    }
    if (already_here(mysh, command, my_strcpy(new_var)) == 1)
        return 0;
    add_var_in_env(mysh, new_var);
    return 0;
}
