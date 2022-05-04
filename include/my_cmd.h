/*
** EPITECH PROJECT, 2022
** PSU [WSL: Ubuntu]
** File description:
** my_cmd
*/

#pragma once

    #include "struct.h"

    ////////////////////////////////////////////////////////////
    /// \brief Change working directory
    ///
    /// \param mysh The struct with all the data needed
    ///
    /// \return Return 0
    ///
    ////////////////////////////////////////////////////////////
    int my_cd(mysh_t *mysh);

    ////////////////////////////////////////////////////////////
    /// \brief Display the whole environment
    ///
    /// \param mysh The struct with all the data needed
    ///
    /// \return Return 0
    ///
    ////////////////////////////////////////////////////////////
    int my_env(mysh_t *mysh);

    ////////////////////////////////////////////////////////////
    /// \brief Add an environment variable or replace actual value
    ///
    /// \param mysh The struct with all the data needed
    ///
    /// \return Return 0 if OK | 84 if KO
    ///
    ////////////////////////////////////////////////////////////
    int my_setenv(mysh_t *mysh);

    ////////////////////////////////////////////////////////////
    /// \brief Remove an environment variable
    ///
    /// \param mysh The struct with all the data needed
    ///
    /// \return Return 0 if OK | 84 if KO
    ///
    ////////////////////////////////////////////////////////////
    int my_unsetenv(mysh_t *mysh);
