/*
** EPITECH PROJECT, 2022
** shell_programing
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    ////////////////////////////////////////////////////////////
    /// \brief Linked_list to stock input and env
    ///
    /// \param input   char ** to stock input
    ///
    /// \param env   char ** to stock env
    ///
    /// \param path_alt   char * to stock PATH if it is unset
    ///
    ////////////////////////////////////////////////////////////
    typedef struct {
        char **input;
        char **env;
        char *path_alt;
    } mysh_t;
#endif /* !STRUCT_H_ */
