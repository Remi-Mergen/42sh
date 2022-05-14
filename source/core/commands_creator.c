/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** commands_creator
*/

#include "struct.h"
#include "stdlib.h"
#include "prototype.h"

char **my_stwa(char const *str, char div);

void add_command_in_list(list_commands_t **commands_list, list_commands_t *command)
{
    list_commands_t *commands_node = malloc(sizeof(list_commands_t));
    commands_node->command = command;
    commands_node->next = *commands_list;
    *commands_list = commands_node;
    return;
}

list_commands_t *commands_creator(mysh_t *mysh, char **env)
{
    list_commands_t *commands_list = NULL;
    command_t *command = malloc(sizeof(command_t));
    char **list = my_stwa(mysh->input, ';');

    if (!commands_list)
        return NULL;
    command->env = env;
    //TODO? is_a_builtin_command(command, mysh);
    for (int i = 0; list[i]; ++i) {
        define_path(list[i], &command, mysh);
        // *pipe_handler(list[i], &command, mysh);
        // *redirect_left_handler(list[i], &command, mysh);
        // *dredirect_left_handler(list[i], &command, mysh);
        // *redirect_right_handler(list[i], &command, mysh);
        // *dredirect_right_handler(list[i], &command, mysh);
        add_command_in_list(&commands_list, command);
    }
    return commands_list;
}
