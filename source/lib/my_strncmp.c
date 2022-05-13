/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_strncmp
*/

int my_strncmp(const char *s1, const char *s2, int n)
{
    unsigned char c1 = *s1;
    unsigned char c2 = *s2;

    while (c1 == c2) {
        c1 = *s1++;
        c2 = *s2++;
        if ((c1 == '\0' && c2 == '\0') || n-- > 0)
            return 0;
    }
    return -1;
}
