/*
** EPITECH PROJECT, 2022
** minishell_1 [WSL: Ubuntu]
** File description:
** array_len
*/

unsigned int my_array_len(char **array)
{
    unsigned int i = 0;

    for (; array[i]; ++i);
    return i;
}
