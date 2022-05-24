/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** commands_creator
*/

#include "lib.h"
#include "struct.h"
#include "define.h"
#include "stdlib.h"
#include "prototype.h"
#include <stdio.h>//TODO remove
static void get_command(mysh_t **mysh, command_t **command,
                                            char *input, UNUSED char **env);

static void fill_args(char *input, command_t *command, UNUSED mysh_t *mysh)
{
    command->args = my_stwa(input, ' ');
}

void add_command_in_end_of_list(list_commands_t **commands_list,
                                                        command_t *command)
{
    if (*commands_list == NULL) {
        *commands_list = malloc(sizeof(list_commands_t));
        (*commands_list)->command = command;
        (*commands_list)->next = NULL;
    } else {
        list_commands_t *tmp = *commands_list;

        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = malloc(sizeof(list_commands_t));
        tmp->next->command = command;
        tmp->next->next = NULL;
    }
    return;
}

static void builtin_command_handler(UNUSED mysh_t *mysh,
                                        command_t *command, char **builtin)
{
    for (unsigned int i = 0; i < my_array_len(builtin); i++) {
        if (my_strcmp(builtin[i], command->args[0]) == 0) {
            command->builtin = &mysh->builtin_commands[i];
            return;
        }
    }
    command->builtin = NULL;
    return;
}

static void pipe_handler(char *input, UNUSED command_t **command,
                        UNUSED mysh_t *mysh, char **env)
{
    char **splited = my_stwa(input, '|');
    if (my_array_len(splited) == 1)
        return;
    command_t *pipe_command = malloc(sizeof(command_t));
    command_t *tmp = malloc(sizeof(command_t));
    pipe_command->prev_pipe = *command;
    for (unsigned int i = 1; splited[i]; ++i) {
        tmp->env = env;
        get_command(&mysh, &tmp, splited[i], env);
        pipe_command->next_pipe = tmp;
        pipe_command = tmp;
        tmp = malloc(sizeof(command_t));
        tmp->prev_pipe = pipe_command;
    }
    // ?free(tmp);
}

static void get_command(mysh_t **mysh, command_t **command,
                                            char *input, UNUSED char **env)
{
    char *builtin[6] = {"cd", "env", "setenv", "unsetenv", "exit", NULL};

    fill_args(input, *command, (*mysh));
    builtin_command_handler((*mysh), *command, builtin);
    define_path(input, *command, (*mysh));
    pipe_handler(input, command, (*mysh), env);
    //* redirect_left_handler(input, command, mysh);
    //! dredirect_left_handler(input, command, mysh);
    //* redirect_right_handler(input, command, mysh);
    //* dredirect_right_handler(input, command, mysh);
}

void commands_creator(mysh_t **mysh, char **env)
{
    list_commands_t *commands_list = NULL;
    command_t *command = NULL;
    char **list = my_stwa((*mysh)->input, ';');

    for (int i = 0; list[i]; ++i) {
        command = malloc(sizeof(command_t));
        command->env = env;
        get_command(mysh, &command, list[i], env);
        add_command_in_end_of_list(&commands_list, command);
    }
    (*mysh)->commands_list = commands_list;
    return;
}
