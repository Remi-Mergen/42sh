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

int main(int argc, UNUSED char **argv, char **env)
{
    mysh_t *mysh = init_struct(env);

    if (error_handling(argc) != 0)
        return 84;
    if (isatty(0) == 0) {
        return process_not_tty(mysh);
    }
    return process_tty(mysh);
}
