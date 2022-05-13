/*
** EPITECH PROJECT, 2022
** shell_programing
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    struct mysh_s;

    ////////////////////////////////////////////////////////////
    /// \brief Store all env in a linked list
    ///
    /// \param data   char * to store a line of env
    ///
    /// \param next   ptr to next element in the linked list
    ///
    /// \return Anything. It's a struct bro
    ///
    ////////////////////////////////////////////////////////////
    typedef struct list_env {
        char *data;
        struct list_env *next;
    } list_env_t;

    ////////////////////////////////////////////////////////////
    /// \brief linked list to store my builtin commands
    ///
    /// \param command   char * to store the name of the command
    ///
    /// \param fct_ptr   ptr to command function
    ///
    /// \return Anything. It's a struct bro
    ///
    ////////////////////////////////////////////////////////////
    typedef struct builtin_commands {
        char *command;
        int (*fct_ptr)(struct mysh_s *);
    } builtin_commands_t;

    ////////////////////////////////////////////////////////////
    /// \brief Store all env in a linked list
    ///
    /// \param env              char ** to store env for execve
    /// \param builtin          NULL if command is not a builtin
    /// \param path             NULL if builtin command, else path to execve
    /// \param output           output of the command
    /// \param args             arguments of the command (1st is always the path)
    /// \param return_value     value returned by the command
    /// \param prev_pipe        ptr to the previous command if pipe exist
    /// \param next_pipe        ptr to the next command if pipe exist
    /// \param redirect_stdout  fd to redirect output
    /// \param redirect_stdin   fd to redirect input
    /// \param eof              Should we write at the end of the file?
    /// \param heredoc          keyword to stop `<<` command
    ///
    /// \return Anything. It's a struct bro
    ///
    ////////////////////////////////////////////////////////////
    typedef struct command {
        char **env;
        builtin_commands_t *builtin;
        char *path;
        char *output;
        char **args;
        int return_value;
        struct command *prev_pipe;
        struct command *next_pipe;
        int redirect_stdout;
        int redirect_stdin;
        int eof;
        char *heredoc;
    } command_t;

    ////////////////////////////////////////////////////////////
    /// \brief Store the lost of the command in the user input
    ///
    /// \param data   char * to store a line of env
    ///
    /// \param next   ptr to next element in the linked list
    ///
    /// \return Anything. It's a struct bro
    ///
    ////////////////////////////////////////////////////////////
    typedef struct list_commands {
        command_t *command;
        struct list_commands *next;
    } list_commands_t;

    ////////////////////////////////////////////////////////////
    /// \brief Store everything
    ///
    /// \param commands_list        Linked list of commands asked in the input
    /// \param builtin_commands     Linked list of builtin commands
    /// \param env                  Linekd list of env
    /// \param last_return_value    Store the last return value
    /// \param input                Char * to store the user input
    /// \param error                Error handling in loop
    /// \param is_tty               Is it a terminal
    /// \param exit                 Store return value and used for error handling
    ///
    /// \return Anything. It's a struct bro
    ///
    ////////////////////////////////////////////////////////////
    typedef struct mysh_s {
        list_commands_t *commands_list;
        builtin_commands_t builtin_commands[5];
        list_env_t *env;
        int last_return_value;
        char *input;
        int error;
        int is_tty;
        int exit;
    } mysh_t;

#endif /* !STRUCT_H_ */
