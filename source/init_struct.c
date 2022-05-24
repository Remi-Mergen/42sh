/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** init_struct
*/

#include "struct.h"
#include "define.h"
#include <stddef.h>
#include <stdlib.h>
int my_cd(mysh_t *mysh, UNUSED command_t *command);
int my_env(mysh_t *mysh, UNUSED command_t *command);
int my_setenv(mysh_t *mysh, UNUSED command_t *command);
int my_unsetenv(mysh_t *mysh, UNUSED command_t *command);
int my_exit(UNUSED mysh_t *mysh, UNUSED command_t *command);

static void init_builtin_commands(mysh_t *mysh)
{
    mysh->builtin_commands[0].command = "cd";
    mysh->builtin_commands[0].fct_ptr = &my_cd;
    mysh->builtin_commands[1].command = "env";
    mysh->builtin_commands[1].fct_ptr = &my_env;
    mysh->builtin_commands[2].command = "setenv";
    mysh->builtin_commands[2].fct_ptr = &my_setenv;
    mysh->builtin_commands[3].command = "unsetenv";
    mysh->builtin_commands[3].fct_ptr = &my_unsetenv;
    mysh->builtin_commands[4].command = "exit";
    mysh->builtin_commands[4].fct_ptr = &my_exit;

}

static list_env_t *init_env(char **env)
{
    list_env_t *node = malloc(sizeof(list_env_t));

    node->data = env[0];
    node->next = NULL;
    for (int i = 1; env[i]; i++) {
        list_env_t *tmp = malloc(sizeof(list_env_t));
        tmp->data = env[i];
        tmp->next = node;
        node = tmp;
    }
    return node;
}

mysh_t *init_struct(char **env)
{
    mysh_t *mysh = malloc(sizeof(mysh_t));

    mysh->commands_list = NULL;
    init_builtin_commands(mysh);
    mysh->env = init_env(env);
    mysh->last_return_value = 0;
    mysh->input = NULL;
    mysh->error = 0;
    mysh->is_tty = 0;
    mysh->exit = 0;
    return mysh;
}
