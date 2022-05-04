/*
** EPITECH PROJECT, 2022
** minishell_1
** File description:
** my_setenv
*/

#include "minif.h"
#include "struct.h"
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

static void already_here(mysh_t *mysh, int index, char *str)
{
    mysh->env[index] = malloc(sizeof(char) * my_strlen(str));
    mysh->env[index] = str;
    if (my_strcmp(mysh->input[1], "PATH") == 0)
        mysh->path_alt = str;
}

static char **add_new_var_in_env(int len, mysh_t *mysh, char *str)
{
    char **new_env = malloc(sizeof(char *) * len);

    for (int i = 0; mysh->env[i]; ++i) {
        new_env[i] = malloc(sizeof(char) * my_strlen(mysh->env[i]));
        new_env[i] = mysh->env[i];
    }
    new_env[len - 1] = malloc(sizeof(char) * my_strlen(str));
    new_env[len - 1] = str;
    new_env[len] = NULL;
    return new_env;
}

int my_setenv(mysh_t *mysh)
{
    int index = find_in_env(mysh->env, mysh->input[1]);
    char *str = my_strcat(my_strcat(my_strcat(mysh->input[1], "="),
                                                    mysh->input[2]), "\0");

    if (my_array_len(mysh->input) > 3) {
        minif("setenv: Too many arguments.");
        return 1;
    }
    if (index != -1) {
        already_here(mysh, index, str);
        return 0;
    }
    mysh->env = add_new_var_in_env(my_array_len(mysh->env) + 1, mysh, str);
    return 0;
}
