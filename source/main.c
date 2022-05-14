/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** main
*/

#include "lib.h"
#include "core.h"
#include "minif.h"
#include "import.h"
#include "struct.h"
#include "define.h"
#include "prototype.h"
#include <stdbool.h>

static int parser_not_tty(mysh_t *mysh)
{
    size_t size = 0;
    printf("I'm not a tty\n");

    while(getline(&mysh->input, &size, stdin) != -1) {
        size = size;
    }
    return 0;
}

static int parser_tty(mysh_t *mysh, char **env)
{
    size_t size = 0;
    printf("I'm a tty\n");

    while(true) {
        if (getline(&mysh->input, &size, stdin) == -1)
            return 84;
        if (my_strlen(mysh->input) == 0 || mysh->input[0] == '\n')
            continue;
        mysh->commands_list = commands_creator(mysh, env);
        execve(mysh->commands_list->command->path, mysh->commands_list->command->args, mysh->commands_list->command->env);
    }
}

static int error_handling(int argc)
{
    if (argc != 1) {
        write(2, "usage: 42sh\n", 12);
        return -1;
    }
    return 0;
}

int main(int argc, UNUSED char **argv, char **env)
{
    mysh_t *mysh = init_struct(env);

    if (error_handling(argc) != 0)
        return 84;
    if (isatty(0) == 0) {
        return parser_not_tty(mysh);
    }
    return parser_tty(mysh, env);
}
