##
## EPITECH PROJECT, 2022
## minishell2
## File description:
## Makefile
##

SRC				:=		$(shell find source/ -name "*.c")

SRC_DIR         :=      source/

BUILD_DIR       :=      build/

INCLUDE_DIR     :=      include/

OBJECTS         :=      $(addprefix $(BUILD_DIR), $(SRC:$(SRC_DIR)%.c=%.o))

BINARY          :=      mysh

CFLAGS          :=      -Wall -Wextra -Wpedantic -Werror -g

all: $(BINARY)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BINARY): $(OBJECTS)
	@gcc $(OBJECTS)  $(CFLAGS) -o $(BINARY)
	@echo "\e[38;5;28m================ Compiling: Done   =======\
	=========\e[0;0m"

clean:
	@rm -rf $(OBJECTS)
	@rm -f *vgcore.*
	@echo "\e[38;5;39m================ Clean:     Done   =========\
	=======\e[0;0m"

fclean: clean
	@rm -rf $(BINARY)
	@rm -rf $(BUILD_DIR)
	@echo "\e[38;5;202m================ Fclean:    Done   ==========\
	======\e[0;0m"
	@find tester/ -name "mysh" -delete

re: fclean all


.PHONY: re clean fclean all
