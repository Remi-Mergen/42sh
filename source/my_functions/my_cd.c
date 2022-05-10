/*
** EPITECH PROJECT, 2022
** minishell_1
** File description:
** my_cd
*/

#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib.h"
#include "struct.h"

static int finder_in_env(mysh_t *mysh, char *word)
{
    int i = 0;

    for (; mysh->env[i]; ++i)
        if (my_strcmp(get_first_word(mysh->env[i], '='), word) == 0)
            break;
    return i;
}

static int cd_error(char *dir)
{
    DIR *dirptr;

    if (access ( dir, F_OK ) != -1 ) {
        if ((dirptr = opendir(dir)) != NULL) {
            closedir (dirptr);
        } else {
            write(2, dir, my_strlen(dir));
            write(2, ": Not a directory.\n", 19);
            return 1;
        }
    } else {
        write(2, dir, my_strlen(dir));
        write(2, ": No such file or directory.\n", 29);
        return 1;
    };
    return 0;
}

static void change_pwd(mysh_t *mysh)
{
    char *new_pwd = getcwd(NULL, 0);
    char **old_pwd;
    int i = 0;
    int j = 0;

    new_pwd = my_strcat("PWD=", new_pwd);
    i = finder_in_env(mysh, "PWD");
    j = finder_in_env(mysh, "OLDPWD");
    old_pwd = my_stwa(mysh->env[i], '=');
    mysh->env[j] = my_strcat("OLDPWD=", old_pwd[1]);
    mysh->env[i] = new_pwd;
    return;
}

int change_to_old_pwd(mysh_t *mysh)
{
    int i = finder_in_env(mysh, "OLDPWD");
    int j = finder_in_env(mysh, "PWD");
    char **old_pwd = my_stwa(mysh->env[i], '=');

    if (chdir(old_pwd[1]) == -1)
        return 84;
    mysh->env[i] = my_strcat("OLDPWD=", getcwd(NULL, 0));
    mysh->env[j] = my_strcat("PWD=", old_pwd[1]);
    return 0;
}

int my_cd(mysh_t *mysh)
{
    if (my_array_len(mysh->input) != 2)
        return 84;
    if (mysh->input[1][0] == '-')
        return change_to_old_pwd(mysh);
    if (chdir(mysh->input[1]) == 0) {
        change_pwd(mysh);
        return 0;
    }
    else
        return cd_error(mysh->input[1]);
}
