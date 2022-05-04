/*
** EPITECH PROJECT, 2022
** minishell_1
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
void display_prompt(int exit_code);

static mysh_t *init_struct(char **env)
{
    mysh_t *element = malloc(sizeof(mysh_t));
    element->env = env;
    element->path_alt = env[find_in_env(env, "PATH")];
    return element;
}

static char **commands(char ***input_array, char *input, int exit_code)
{
    *input_array = my_stwa(input, ' ');
    if (my_strcmp(*input_array[0], "exit") == 0)
        exit(exit_code);
    return *input_array;
}

static int process_tty(mysh_t *mysh)
{
    int exit_code = 0;
    char *input = NULL;
    char **input_array = NULL;

    while (true) {
        display_prompt(exit_code);
        input = get_input();
        if (input == NULL)
            return exit_code;
        if (my_strlen(input) == 1)
            continue;
        input[my_strlen(input) - 1] = '\0';
        mysh->input = commands(&input_array, input, exit_code);
        exit_code = fork_to_exe(mysh);
    }
}

static int process_not_tty(mysh_t *mysh)
{
    int exit_code = 0;
    size_t size = 0;
    char *input = NULL;
    char **input_array = NULL;

    while (getline(&input, &size, stdin) != -1) {
        if (input == NULL || my_strlen(input) == 1)
            return exit_code;
        input[my_strlen(input) - 1] = '\0';
        mysh->input = commands(&input_array, input, exit_code);
        exit_code = fork_to_exe(mysh);
    }
    return exit_code;
}

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
