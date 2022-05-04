##
## EPITECH PROJECT, 2022
## My_sort_word_array
## File description:
## Makefile
##

CC = gcc

SRC	 		:=	$(shell find source/ -name "*.c")

INC	 		:= 	-I./include

LIB 		:=	-lm

OBJ			:=	$(SRC:c=o)

CFLAGS  	:=	-Wall -Wextra -Wpedantic $(INC)
CFLAGS 		+=	-Werror -Wno-error=unused-parameter -Wno-error=unused-function

NAME		=	mysh


all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ $(LIB)
	@echo "\e[38;5;28m================ Compiling: Done =======\
	=========\e[0;0m"

clean:
	@rm -f $(OBJ)
	@rm -f *vgcore.*
	@echo "\e[38;5;202m================  clean: Done =========\
	=======\e[0;0m"

fclean:		clean
	@rm -f $(NAME)
	@echo "\e[38;5;202m================ fclean: Done ==========\
	======\e[0;0m"

re:			fclean all

exe:	re
	@echo
	./$(NAME)

.PHONY: re clean fclean all
