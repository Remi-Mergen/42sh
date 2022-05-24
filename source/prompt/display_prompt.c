/*
** EPITECH PROJECT, 2022
** B-PSU-210-STG-2-1-minishell2-remi.mergen [WSL: Ubuntu-18.04]
** File description:
** display_prompt
*/

#include "minif.h"
#include <stdio.h>

void display_prompt(int exit_code)
{
    minif("\n[%s]\n", getcwd(NULL, 0));
    minif("%d $>", exit_code);
}
