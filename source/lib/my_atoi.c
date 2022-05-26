/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_atoi
*/

static int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

unsigned int my_atoi( char *str )
{
    unsigned int number = 0;
    char *ptr = str;

    while(is_digit(*ptr))
        number = number * 10 + *ptr++ - '0';
    return number;
}
