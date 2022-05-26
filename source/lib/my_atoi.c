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

int my_atoi( char *str )
{
    int number = 0;
    int neg = 1;
    char *ptr = str;

    if (str[0] == '-') {
        neg = -1;
        ++ptr;
    }
    while(is_digit(*ptr))
        number = number * 10 + *ptr++ - '0';
    return number * neg;
}
