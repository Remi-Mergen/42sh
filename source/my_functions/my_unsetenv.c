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
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void my_new_env(mysh_t *mysh, int i)
{
    unsigned int array_len = my_array_len(mysh->env);
    char **new_env = malloc(sizeof(char *) * (array_len));
    int k = 0;

    for (unsigned int j = 0; j < array_len; ++j) {
        if (j == (unsigned int)i)
            continue;
        new_env[k] = malloc(sizeof(char) * my_strlen(mysh->env[j]));
        new_env[k++] = mysh->env[j];
    }
    new_env[array_len - 1] = NULL;
    // for (int j = 0; mysh->env[j]; ++j)
    //     free(mysh->env[j]);
    // free(mysh->env);
    mysh->env = new_env;
}

int my_unsetenv(mysh_t *mysh)
{
    int index = find_in_env(mysh->env, mysh->input[1]);
    if (index == -1)
        return 0;
    my_new_env(mysh, index);
    return 0;
}
