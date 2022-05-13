/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** define_path
*/

#include "lib.h"
#include "struct.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

static int special_case(char *input, command_t *command,
                                                mysh_t *mysh, char *to_exe)
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
    char **all_path = my_stwa(get_path(mysh->env), ':');
    char *to_exe = my_stwa(input, ' ')[0];

    if (special_case(input, command, mysh, to_exe) == 1)
        return;
    for (int i = 0; all_path[i]; ++i) {
        to_exe = my_strcat(my_strcat(all_path[i], "/"), input[0]);
        if (access(to_exe, F_OK) == 0) {
            command->path = to_exe;
            return;
        }
    }
    minif("%s: Command not found.\n", input);
    return;
}
