/*
** EPITECH PROJECT, 2022
** minishell_1
** File description:
** my_cd
*/

#include "lib.h"
#include "define.h"
#include "struct.h"
#include <stdlib.h>
#include <unistd.h>

static void change_pwd(mysh_t *mysh)
{
    char *new_pwd = my_strcat("PWD=", getcwd(NULL, 0));
    char *old_pwd = NULL;

    for (list_env_t *tmp = mysh->env; tmp; tmp = tmp->next) {
        if (my_strncmp(tmp->data, "PWD", 3) == 0) {
            old_pwd = tmp->data;
            tmp->data = new_pwd;
        }
    }
    for (list_env_t *tmp = mysh->env; tmp; tmp = tmp->next) {
        if (my_strncmp(tmp->data, "OLDPWD", 6) == 0)
            tmp->data = my_strcat("OLDPWD=", old_pwd);
    }
}

int change_to_old_pwd(mysh_t *mysh)
{
    char *old_pwd = my_stwa(get_in_env(mysh->env, "OLDPWD"), '=')[1];

    for (list_env_t *tmp = mysh->env; tmp; tmp = tmp->next) {
        if (my_strncmp(tmp->data, "OLDPWD=",
                                            my_strlen("OLDPWD=")) == 0)
            tmp->data = my_strcat("OLDPWD=", getcwd(NULL, 0));
    }
    if (chdir(old_pwd) == -1)
        return -1;
    for (list_env_t *tmp = mysh->env; tmp; tmp = tmp->next) {
        if (my_strncmp(tmp->data, "PWD=",
                                            my_strlen("PWD=")) == 0)
            tmp->data = my_strcat("PWD=", getcwd(NULL, 0));
    }
    return 0;
}

int my_cd(mysh_t *mysh, UNUSED command_t *command)
{
    if (my_array_len(command->args) != 2)
        return 84;
    if (command->args[0][0] == '-')
        return change_to_old_pwd(mysh);
    if (chdir(command->args[0]) == 0) {
        change_pwd(mysh);
        return 0;
    }
    else
        return 84;
}
