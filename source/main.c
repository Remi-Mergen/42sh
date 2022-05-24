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
void display_prompt(int exit_code);

static int parser_not_tty(mysh_t *mysh)
{
    size_t size = 0;

    while(getline(&mysh->input, &size, stdin) != -1) {
        display_prompt(mysh->last_return_value);
    }
    return 0;
}

static int parser_tty(mysh_t *mysh, char **env)
{
    size_t size = 0;

    while(true) {
        display_prompt(mysh->last_return_value);
        if (getline(&mysh->input, &size, stdin) == -1)
            return 84;
        mysh->input[my_strlen(mysh->input) - 1] = '\0';
        if (my_strlen(mysh->input) == 0 || mysh->input[0] == '\n')
            continue;
        commands_creator(&mysh, env);
        exec_commands(mysh);*
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
