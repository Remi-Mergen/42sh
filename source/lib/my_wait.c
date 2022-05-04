/*
** EPITECH PROJECT, 2022
** minishell_1 [WSL: Ubuntu]
** File description:
** my_wait
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include "lib.h"

int my_wait(pid_t *pid)
{
    int status = 0;

    waitpid(*pid, &status, WUNTRACED);
    if (WIFSIGNALED(status) != 0) {
        if (WTERMSIG(status) == 8 && WCOREDUMP(status) == 0)
            my_puterr("Floating exception\n");
        else if (WTERMSIG(status) != 8 && WCOREDUMP(status) != 0)
            my_puterr("Floating exception (core dumped)\n");
        if (WTERMSIG(status) == 11 && WCOREDUMP(status) == 0)
            my_puterr("Segmentation fault\n");
        else if (WTERMSIG(status) != 11 && WCOREDUMP(status) != 0)
            my_puterr("Segmentation fault (core dumped)\n");
    }
    if (WIFSTOPPED(status) != 0)
        if (WSTOPSIG(status) != 0)
            my_puterr(strsignal(WSTOPSIG(status)));
    return status/256;
}
