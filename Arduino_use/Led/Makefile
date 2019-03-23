## Name of Project

NAME = Control_gpio

## Color for compilating (blue)

COLOR = \0033[1;34m

## List of Directories

INC_DIR = includes
OBJ_DIR = objs
SRC_DIR = srcs

ENTRY_DIR = entry
ARDUINO_DIR = arduino

## Compilating Utilities

FAST = -Ofast
FLAGS = -Wall -Wextra -Werror $(FAST) $(DEBUG) -lwiringPi -x c++

HOME =  $(shell pwd)

CC = c++ $(FLAGS) $(INC)

## List of Files

INCLUDE_H = gpio_arduino

ENTRY_FT = entry
ARDUINO_FT = arduino

## List of Utilities

SRC = $(ENTRY_FT:%=$(SRC_DIR)/$(ENTRY_DIR)/%.ino) \
	$(ARDUINO_FT:%=$(SRC_DIR)/$(ARDUINO_DIR)/%.ino) \

OBJ = $(SRC:$(SRC_DIR)%.ino=$(OBJ_DIR)%.o)

OBJ_DIRS = $(ENTRY_DIR:%=$(OBJ_DIR)/%) \
	$(ARDUINO_DIR:%=$(OBJ_DIR)/%) \


INCLUDES = $(INCLUDE_H:%=./$(INC_DIR)/%.h)
## Rules of Makefile

all: $(NAME)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;30m[All OK]\0033[1;37m"

$(OBJ_DIRS):
	@mkdir -p $@
	@echo "$(COLOR)Creating :\t\0033[0;32m$@\0033[1;37m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.ino $(INCLUDES)
	@$(CC)  -c $< -o $@
	@echo "$(COLOR)Compiled :\t\0033[0;32m$(@:$(OBJ_DIR)/%=%)\0033[1;37m"

$(NAME): $(OBJ_DIRS) $(SRC) $(INCLUDES)
	@$(MAKE) -j -s $(OBJ)
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[0;32m[Created]\0033[1;37m"
	@$(CC) -x none  $(OBJ) -o $@
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[0;32m[Created]\0033[1;37m"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[0;31m[Deleted]\0033[1;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[0;31m[Deleted]\0033[1;37m"

re: fclean all

.PHONY: all clean fclean re
