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
    /// \param mysh     main structure
    ///
    /// \param env      enviroment
    ///
    /// \return         linked list of command
    ///
    ////////////////////////////////////////////////////////////
    list_commands_t *commands_creator(mysh_t *mysh, char **env);

#endif /* !CORE_H_ */
