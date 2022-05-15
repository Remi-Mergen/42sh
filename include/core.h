/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** core
*/

#ifndef CORE_H_
    #define CORE_H_

    #include "struct.h"

    ////////////////////////////////////////////////////////////
    /// \brief          Parse user-input to split command
    ///
    /// \param mysh     Adresse of main structure
    ///
    /// \param env      Enviroment
    ///
    /// \return         Linked list of command
    ///
    ////////////////////////////////////////////////////////////
    void commands_creator(mysh_t **mysh, char **env);

    ////////////////////////////////////////////////////////////
    /// \brief          Execute commands in commands_list
    ///
    /// \param mysh     Main structure with the commands list
    ///
    /// \return         status returned by the process
    ///
    ////////////////////////////////////////////////////////////
    int exec_commands(mysh_t *mysh);

#endif /* !CORE_H_ */
