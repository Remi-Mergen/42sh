/*
** EPITECH PROJECT, 2022
** shell [WSL: Ubuntu-18.04]
** File description:
** find_in_env
*/

#include "lib.h"

int find_in_env(char **env, char *target)
{
    for (int i = 0; env[i]; ++i) {
        if (my_strcmp(target,
            get_first_word(env[i], '=')) == 0) {
            return i;
        }
    }
    return -1;
}