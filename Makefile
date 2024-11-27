# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 16:31:04 by paalexan          #+#    #+#              #
#    Updated: 2024/11/26 19:44:06 by paalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME := libftprintf.a

# Compiler and Flags
CC := cc
CFLAGS := -Wall -Wextra -Werror
CFLAGS += -g

# Directories
SRC_DIR := .
OBJ_DIR := obj

# Source files
SRC := $(addprefix $(SRC_DIR)/, \
	ft_printf.c ft_printf_numbers.c ft_printf_utils.c ft_parser_numbers.c \
	ft_printf_utils_str.c)

# Convert source file names to object file names
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

# **************************************************************************** #
#                                COMPILATION                                   #
# **************************************************************************** #

# Default target to create the library
all: $(NAME)

# Create library archive from object files
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(BGRN)Library $(NAME) created successfully!$(D)"

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BYEL)Compiled:$(D) $<"

# Remove object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(BRED)Object files cleaned!$(D)"

# Remove object files and the library
fclean: clean
	@rm -f $(NAME)
	@echo "$(BRED)All cleaned up!$(D)"

# Rebuild the library
re: fclean all

# Declare phony targets to avoid conflicts with files of the same name
.PHONY: all clean fclean re

# **************************************************************************** #
#                                  UTILS                                       #
# **************************************************************************** #

# Colors
B   := $(shell tput bold)
BLA := $(shell tput setaf 0)
RED := $(shell tput setaf 1)
GRN := $(shell tput setaf 2)
YEL := $(shell tput setaf 3)
BLU := $(shell tput setaf 4)
MAG := $(shell tput setaf 5)
CYA := $(shell tput setaf 6)
WHI := $(shell tput setaf 7)
GRE := $(shell tput setaf 8)
BRED := $(shell tput setaf 9)
BGRN := $(shell tput setaf 10)
BYEL := $(shell tput setaf 11)
BBLU := $(shell tput setaf 12)
BMAG := $(shell tput setaf 13)
BCYA := $(shell tput setaf 14)
BWHI := $(shell tput setaf 15)
D := $(shell tput sgr0)
BEL := $(shell tput bel)
