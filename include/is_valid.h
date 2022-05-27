/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** is_valid
*/

#ifndef IS_VALID_H_
    #define IS_VALID_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdbool.h>

    static inline bool is_valid(char *str)
    {
        for (int i = 0; str[i]; ++i) {
            if (str[i] != ' ' && str[i] != '|')
                return true;
        }
        if (write(2, "Invalid null command.\n", 22) == -1)
            perror("write");
        return false;
    }

#endif /* !IS_VALID_H_ */
