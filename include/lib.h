/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** lib
*/

#pragma once

    #include "struct.h"
    #include <stddef.h>
    #include <sys/types.h>

    ////////////////////////////////////////////////////////////
    /// \brief          Find a variable in env
    ///
    /// \param env      The env
    ///
    /// \param target   The target to search
    ///
    /// \return         Return the data of the variable
    ///
    ////////////////////////////////////////////////////////////
    char *get_in_env(list_env_t *env, char *target);

    ////////////////////////////////////////////////////////////
    /// \brief              Get a world before the first separator
    ///
    /// \param line         The string to get the word
    ///
    /// \param separator    The separator
    ///
    /// \return             Return the word before the separator
    ///
    ////////////////////////////////////////////////////////////
    char *get_first_word(char *line, char separator);

    ////////////////////////////////////////////////////////////
    /// \brief      Get user-input in stdin using getline
    ///
    /// \return     Return the user input in a char *
    ///
    ////////////////////////////////////////////////////////////
    char *get_input(void);

    ////////////////////////////////////////////////////////////
    /// \brief          Get the length of an array
    ///
    /// \param array    The string to get the length
    ///
    /// \return         Return the length
    ///
    ////////////////////////////////////////////////////////////
    unsigned int my_array_len(char **array);

    ////////////////////////////////////////////////////////////
    /// \brief          Cast a string into a unsigned int
    ///
    /// \param str      The number to cast
    ///
    /// \return         Return the number in an unsigned int
    ///
    ////////////////////////////////////////////////////////////
    unsigned int my_atoi( char *str );

    ////////////////////////////////////////////////////////////
    /// \brief      Write in error canal
    ///
    /// \param s    The string to be wrote
    ///
    /// \return     Return anything
    ///
    ////////////////////////////////////////////////////////////
    void my_puterr(char *s);

    ////////////////////////////////////////////////////////////
    /// \brief          Join two strings
    ///
    /// \param src1     First string to join
    ///
    /// \param src2     Second string to join
    ///
    /// \return         Return a string containing both strings
    ///
    ////////////////////////////////////////////////////////////
    char *my_strcat(char *src1, char *src2);

    ////////////////////////////////////////////////////////////
    /// \brief      Compare two strings
    ///
    /// \param s1   First string to compare
    ///
    /// \param s2   Second string to compare
    ///
    /// \return     Return 0 is strings are same | -1 if they are different
    ///
    ////////////////////////////////////////////////////////////
    int my_strcmp(const char *s1, const char *s2);

    ////////////////////////////////////////////////////////////
    /// \brief      Get a copy of a string
    ///
    /// \param src  The string to get the copy
    ///
    /// \return     Return the copy of the source
    ///
    ////////////////////////////////////////////////////////////
    char *my_strcpy(const char *src);

    ////////////////////////////////////////////////////////////
    /// \brief      Give the length of a string
    ///
    /// \param s    The string to get the length
    ///
    /// \return     Return the length of the string
    ///
    ////////////////////////////////////////////////////////////
    size_t my_strlen(const char *s);

    ////////////////////////////////////////////////////////////
    /// \brief      Compare two strings
    ///
    /// \param s1   First string to compare
    ///
    /// \param s2   Second string to compare
    ///
    /// \param n    number of characters to compare
    ///
    /// \return Return 0 is strings are same | -1 if they are different
    ///
    ////////////////////////////////////////////////////////////
    int my_strncmp(const char *s1, const char *s2, int n);

    ////////////////////////////////////////////////////////////
    /// \brief      Split string with a separator
    ///
    /// \param str  number of argumets given with the binary
    ///
    /// \param div  number of argumets given with the binary
    ///
    /// \return     Return the string splited in an array
    ///
    ////////////////////////////////////////////////////////////
    char **my_stwa(char const *str, char div);

    ////////////////////////////////////////////////////////////
    /// \brief      Wait child process execution
    ///
    /// \param pid  Pid of the child process
    ///
    /// \return     Return the status
    ///
    ////////////////////////////////////////////////////////////
    int my_wait(pid_t *pid);

    ////////////////////////////////////////////////////////////
    /// \brief          Printr an array of strings
    ///
    /// \param array    array to print
    ///
    /// \return         Return anything
    ///
    ////////////////////////////////////////////////////////////
    void print_array(char **array);
