/*
** EPITECH PROJECT, 2022
** minishell_1
** File description:
** fork_to_exe
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "prototype.h"
#include "lib.h"
#include "my_cmd.h"
#include "struct.h"
#include "minif.h"

void print_array(char **array);

static void exec_bin(mysh_t *mysh)
{
    char **all_path = my_stwa(&mysh->path_alt[5], ':');
    char *tmp = mysh->input[0];

    if (mysh->input[0][0] == '/' && access(tmp, F_OK) == 0) {
        execve(tmp, mysh->input, mysh->env);
        exit(0);
    }
    for (int i = 0; all_path[i]; ++i) {
        tmp = my_strcat(my_strcat(all_path[i], "/"), mysh->input[0]);
        if (access(tmp, F_OK) == 0) {
            execve(tmp, mysh->input, mysh->env);
            exit(0);
        }
    }
    minif("%s: Command not found.\n", mysh->input[0]);
    exit(1);
}

static int execution(mysh_t *mysh)
{
    int exit_code = 0;
    pid_t pid = 0;
    char *commands[4] = {"cd", "env", "setenv", "unsetenv"};
    int (*my_commands[4])(mysh_t *) = {my_cd, my_env, my_setenv, my_unsetenv};

    for (int i = 0; i < 4; i++) {
        if (my_strcmp(commands[i], mysh->input[0]) == 0) {
            exit_code = my_commands[i](mysh);
            return (exit_code);
        }
    }
    pid = fork();
    if (pid == 0) {
        exec_bin(mysh);
    } else
        exit_code = my_wait(&pid);
    return exit_code;
}

int fork_to_exe(mysh_t *mysh)
{
    return (execution(mysh));
}
