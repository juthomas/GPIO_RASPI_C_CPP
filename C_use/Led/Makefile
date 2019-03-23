## Name of Project

NAME = Control_gpio

## Color for compilating (blue)

COLOR = \0033[1;34m

## List of Directories

INC_DIR = includes
OBJ_DIR = objs
SRC_DIR = srcs

ENTRY_DIR = entry

## Compilating Utilities

FAST = -Ofast
FLAGS = -Wall -Wextra -Werror $(FAST) $(DEBUG) -lwiringPi

HOME =  $(shell pwd)

CC = cc $(FLAGS) $(INC)

## List of Functions

ENTRY_FT = entry

## List of Utilities

SRC = $(ENTRY_FT:%=$(SRC_DIR)/$(ENTRY_DIR)/%.c) \

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_DIRS = $(ENTRY_DIR:%=$(OBJ_DIR)/%) \


INCLUDES = $(INCLUDE_H:%=./$(INC_DIR)/%.h)
## Rules of Makefile

all: $(NAME)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;30m[All OK]\0033[1;37m"

$(OBJ_DIRS):
	@mkdir -p $@
	@echo "$(COLOR)Creating :\t\0033[0;32m$@\0033[1;37m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@$(CC)  -c $< -o $@
	@echo "$(COLOR)Compiled :\t\0033[0;32m$(@:$(OBJ_DIR)/%=%)\0033[1;37m"

$(NAME): $(OBJ_DIRS) $(SRC) $(INCLUDES)
	@$(MAKE) -j -s $(OBJ)
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[0;32m[Created]\0033[1;37m"
	@$(CC) $(OBJ) -o $@
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[0;32m[Created]\0033[1;37m"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[0;31m[Deleted]\0033[1;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[0;31m[Deleted]\0033[1;37m"

re: fclean all

norme:
	@norminette $(SRC) $(INC_DIR)/
	@make norme -C $(LIB_DIR)

.PHONY: all clean fclean re
