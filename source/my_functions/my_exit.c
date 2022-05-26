/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_exit
*/

#include "lib.h"
#include "define.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h> //TODO remove

int my_exit(UNUSED mysh_t *mysh, UNUSED command_t *command)
{
    if (command->next_pipe != NULL) {
        mysh->exit = my_atoi(command->args[1]);
        return 0;
    } else if (command->args[1] == NULL)
        exit(mysh->last_return_value);
    else
        exit(my_atoi(command->args[1]));
    return 0;
}
