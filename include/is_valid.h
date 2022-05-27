/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** is_valid
*/

#ifndef IS_VALID_H_
    #define IS_VALID_H_

    #include "struct.h"
    #include <stdio.h>
    #include <unistd.h>
    #include <stdbool.h>

    static inline bool is_valid(mysh_t *mysh, char *str)
    {
        for (int i = 0; str[i]; ++i) {
            if (str[i] != ' ' && str[i] != '|' && str[i] != '<' && str[i] != '>')
                return true;
        }
        printf("str: %s\n", str);
        mysh->last_return_value = 1;
        if (str[0] == '>' || str[0] == '<') {
            if (write(2, "Missing name for redirect.\n", 27) == -1)
                perror("write");
            return false;
        }
        if (write(2, "Invalid null command.\n", 22) == -1)
            perror("write");
        return false;
    }

#endif /* !IS_VALID_H_ */
