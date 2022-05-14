/*
** EPITECH PROJECT, 2022
** shell_programing
** File description:
** prototype
*/

#ifndef PROTOTYPE_H_
    #define PROTOTYPE_H_

    #include "struct.h"

    ////////////////////////////////////////////////////////////
    /// \brief Fork then execute command specified
    ///
    /// \param mysh Struct with all variables needed
    ///
    /// \return Return status returned by child process
    ///
    ////////////////////////////////////////////////////////////
    int fork_to_exe(mysh_t *mysh);

    ////////////////////////////////////////////////////////////
    /// \brief Initialize the main struct
    ///
    /// \param env enviroment variables to store it
    ///
    /// \return Return the struct initialized successfully
    ///
    ////////////////////////////////////////////////////////////
    mysh_t *init_struct(char **env);

    ////////////////////////////////////////////////////////////
    /// \brief Try to find th paht to the command
    ///
    /// \param input    The command asked by the user
    ///
    /// \param command  The command struct to fill
    ///
    /// \param mysh     The main struct
    ///
    /// \return Return the struct initialized successfully
    ///
    ////////////////////////////////////////////////////////////
    void define_path(char *input, command_t *command, mysh_t *mysh);

#endif /* !PROTOTYPE_H_ */
