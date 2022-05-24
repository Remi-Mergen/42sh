/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_exit
*/

#include "define.h"
#include "struct.h"
#include <stdlib.h>

int my_exit(UNUSED mysh_t *mysh, UNUSED command_t *command)
{
    exit(mysh->last_return_value);
}
