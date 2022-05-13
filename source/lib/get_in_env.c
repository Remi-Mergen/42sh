/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** get_in_env
*/

#include "lib.h"
#include "struct.h"

char *get_in_env(list_env_t *env, char *target)
{
    for (list_env_t *tmp = env; tmp; tmp = tmp->next) {
        if (my_strncmp(tmp->data, target, my_strlen(target)) == 0)
            return tmp->data;
    }
}
