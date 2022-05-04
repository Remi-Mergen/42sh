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
    /// \brief Error handling
    ///
    /// \param argc number of argumets given with the binary
    ///
    /// \return Return 0 if OK | 84 if KO
    ///
    ////////////////////////////////////////////////////////////
    int error_handling(int argc);

    ////////////////////////////////////////////////////////////
    /// \brief Fork then execute command specified
    ///
    /// \param mysh Struct with all variables needed
    ///
    /// \return Return status returned by child process
    ///
    ////////////////////////////////////////////////////////////
    int fork_to_exe(mysh_t *mysh);

#endif /* !PROTOTYPE_H_ */
