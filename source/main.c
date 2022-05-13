/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** main
*/

#include <stdbool.h>
#include "lib.h"
#include "minif.h"
#include "import.h"
#include "struct.h"
#include "prototype.h"
#include "define.h"

static int parser_not_tty(mysh_t *mysh)
{
    size_t size = 0;

    while(getline(&mysh->input, &size, stdin) != -1) {

    }
}

static int parser_tty(mysh_t *mysh, char **env)
{
    size_t size = 0;

    while(true) {
        if (getline(&mysh->input, &size, stdin) == -1)
            return 84;
        if (my_strlen(mysh->input) == 0 || mysh->input[0] == '\n')
            continue;
        mysh->commands_list = commands_creator(mysh, env);
    }
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
