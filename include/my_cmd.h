/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_cmd
*/

#pragma once

    #include "struct.h"

    ////////////////////////////////////////////////////////////
    /// \brief          Change working directory
    ///
    /// \param mysh     The struct with all the data needed
    ///
    /// \param command  Options about the command to execute
    ///
    /// \return         Return 0
    ///
    ////////////////////////////////////////////////////////////
    int my_cd(mysh_t *mysh, command_t *command);

    ////////////////////////////////////////////////////////////
    /// \brief          Display the whole environment
    ///
    /// \param mysh     The struct with all the data needed
    ///
    /// \param command  Options about the command to execute
    ///
    /// \return         Return 0
    ///
    ////////////////////////////////////////////////////////////
    int my_env(mysh_t *mysh, command_t *command);

    ////////////////////////////////////////////////////////////
    /// \brief          Add an environment variable or replace actual value
    ///
    /// \param mysh     The struct with all the data needed
    ///
    /// \param command  Options about the command to execute
    ///
    /// \return         Return 0 if OK | 1 if KO
    ///
    ////////////////////////////////////////////////////////////
    int my_setenv(mysh_t *mysh, command_t *command);

    ////////////////////////////////////////////////////////////
    /// \brief          Remove an environment variable
    ///
    /// \param mysh     The struct with all the data needed
    ///
    /// \param command  Options about the command to execute
    ///
    /// \return         Return 0 if OK | 1 if KO
    ///
    ////////////////////////////////////////////////////////////
    int my_unsetenv(mysh_t *mysh, command_t *command);
