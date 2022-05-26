/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** add_command_in_end_of_list
*/

#ifndef ADD_COMMAND_IN_END_OF_LIST_H_
    #define ADD_COMMAND_IN_END_OF_LIST_H_

    #include "struct.h"
    #include <stdlib.h>

    static inline void add_command_in_end_of_list(
                        list_commands_t **commands_list, command_t *command)
    {
        if (*commands_list == NULL) {
            *commands_list = malloc(sizeof(list_commands_t));
            (*commands_list)->command = command;
            (*commands_list)->next = NULL;
        } else {
            list_commands_t *tmp = *commands_list;

            while (tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = malloc(sizeof(list_commands_t));
            tmp->next->command = command;
            tmp->next->next = NULL;
        }
        return;
    }


#endif /* !ADD_COMMAND_IN_END_OF_LIST_H_ */
