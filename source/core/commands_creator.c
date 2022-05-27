/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** commands_creator
*/

#include "lib.h"
#include "struct.h"
#include "redirect.h"
#include "define.h"
#include "stdlib.h"
#include "prototype.h"
#include "add_command_in_end_of_list.h"
static void get_command(mysh_t **mysh, command_t **command,
                                            char *input, UNUSED char **env);

static void fill_args(char *input, command_t *command, UNUSED mysh_t *mysh)
{
    char *sep = "|<>;\0";
    for (unsigned int i = 0; input[i]; ++i) {
        for (int y = 0; sep[y]; ++y) {
            if (input[i] == sep[y]) {
                input[i] = '\0';
                break;
            }
        }
    }
    command->args = my_stwa(input, ' ');
}

static void builtin_command_handler(UNUSED mysh_t *mysh,
                                        command_t *command, char **builtin)
{
    if (command->args == NULL || command->args[0] == NULL)
        return;
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
    (*command)->next_pipe = tmp;
    for (unsigned int i = 1; splited[i]; ++i) {
        init_command(&tmp, env);
        get_command(&mysh, &tmp, splited[i], env);
        pipe_command->next_pipe = tmp;
        pipe_command = tmp;
        tmp = malloc(sizeof(command_t));
        tmp->prev_pipe = pipe_command;
    }
}

static void get_command(mysh_t **mysh, command_t **command,
                                            char *input, UNUSED char **env)
{
    char *builtin[6] = {"cd", "env", "setenv", "unsetenv", "exit", NULL};

    fill_args(my_strcpy(input), *command, (*mysh));
    builtin_command_handler((*mysh), *command, builtin);
    define_path(my_strcpy(input), *command, (*mysh));
    redirect_and_double_right_handler(*mysh, input, command);
    redirect_left_handler(*mysh, input, command);
    return;
}

void commands_creator(mysh_t **mysh, char **env)
{
    list_commands_t *commands_list = NULL;
    command_t *command = NULL;
    char **list = my_stwa((*mysh)->input, ';');

    for (unsigned int i = 0; list[i]; ++i) {
        command = malloc(sizeof(command_t));
        init_command(&command, env);
        get_command(mysh, &command, list[i], env);
        pipe_handler(my_strcpy(list[i]), &command, (*mysh), env);
        add_command_in_end_of_list(&commands_list, command);
    }
    (*mysh)->commands_list = commands_list;
    return;
}
