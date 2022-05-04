/*
** EPITECH PROJECT, 2019
** GITHUB_minif_2018
** File description:
** minif
*/

#ifndef MINIF_H_
    #define MINIF_H_

    #include <unistd.h>
    #include <stdarg.h>

    typedef size_t (*ptr)(va_list);

    ////////////////////////////////////////////////////////////
    /// \brief write formatted output to stdout
    ///
    /// \param str   output format
    ///
    ////////////////////////////////////////////////////////////
    size_t minif(const char * const str, ...);

#endif /* MINIF_H_ */
