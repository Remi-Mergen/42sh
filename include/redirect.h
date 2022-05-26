/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** redirect
*/

#ifndef REDIRECT_H_
    #define REDIRECT_H_

    #include "struct.h"
    #include "define.h"

    void redirect_and_double_right_handler(char *input, command_t **command);
    void redirect_left_handler(char *input, UNUSED command_t **command);

#endif /* !REDIRECT_H_ */
