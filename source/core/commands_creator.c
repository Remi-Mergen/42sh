/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** commands_creator
*/

#include "struct.h"
#include "define.h"
#include "stdlib.h"
#include "prototype.h"
#include <stdio.h>//TODO remove

char **my_stwa(char const *str, char div);

static void fill_args(char *input, command_t *command, UNUSED mysh_t *mysh)
{
    command->args = my_stwa(input, ' ');
}

void add_command_in_list(list_commands_t **commands_list, command_t *command)
{
    list_commands_t *commands_node = malloc(sizeof(list_commands_t));
    commands_node->command = command;
    commands_node->next = *commands_list;
    *commands_list = commands_node;
    return;
}

void commands_creator(mysh_t **mysh, char **env)
{
    list_commands_t *commands_list = NULL;
    // command_t *command = NULL;
    char **list = my_stwa((*mysh)->input, ';');

    for (int i = 0; list[i]; ++i) {
        command_t *command = malloc(sizeof(command_t));
        command->env = env;
        define_path(list[i], command, (*mysh));
        fill_args(list[i], command, (*mysh));
        //TODO! is_a_builtin_command(command, mysh);
        // *pipe_handler(list[i], &command, mysh);
        // *redirect_left_handler(list[i], &command, mysh);
        // *dredirect_left_handler(list[i], &command, mysh);
        // *redirect_right_handler(list[i], &command, mysh);
        // *dredirect_right_handler(list[i], &command, mysh);
        add_command_in_list(&commands_list, command);
    }
    (*mysh)->commands_list = commands_list;
    return;
}
