/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** define_path
*/

#include "lib.h"
#include "minif.h"
#include "struct.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>//TODO remove

static int special_case(char *input, command_t *command, char *to_exe)
{
    if (input[0] == '/' && access(to_exe, F_OK) == 0) {
        command->path = to_exe;
        return 1;
    }
    if (my_strncmp(to_exe, "./", 2) == 0) {
        to_exe = my_strcat(getcwd(NULL, 0), &to_exe[1]);
        if (access(to_exe, F_OK) == 0) {
            command->path = to_exe;
            return 1;
        }
    }
    return 0;
}

void define_path(char *input, command_t *command, mysh_t *mysh)
{
    char **all_path = my_stwa(&get_in_env(mysh->env, "PATH")[5], ':');
    char *to_exe = my_stwa(input, ' ')[0];
    char *tmp = NULL;

    if (special_case(input, command, to_exe) == 1)
        return;
    for (int i = 0; all_path[i]; ++i) {
        tmp = my_strcat(my_strcat(all_path[i], "/"), to_exe);
        if (access(tmp, F_OK) == 0) {
            command->path = tmp;
            return;
        }
    }
    minif("%s: Command not found.\n", input);
    return;
}
