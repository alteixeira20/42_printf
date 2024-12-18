# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 16:31:04 by paalexan          #+#    #+#              #
#    Updated: 2024/12/18 14:38:02 by paalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME := libftprintf.a

# Compiler and Flags
CC := cc
CFLAGS := -Wall -Wextra -Werror
CFLAGS += -g

# Directories
SRC_DIR := src
SRCB_DIR := srcb
OBJ_DIR := obj
OBJB_DIR := objb

# Source files
SRC := $(addprefix $(SRC_DIR)/, \
	ft_printf.c ft_printf_numbers.c ft_printf_hex.c ft_printf_strings.c \
	ft_printf_utils_numbers.c ft_printf_utils_hex.c ft_printf_utils_str.c \
	ft_padding.c ft_padding_utils.c ft_parser.c)

SRCB := $(addprefix $(SRCB_DIR)/, \
	ft_printf_bonus.c ft_printf_numbers_bonus.c ft_printf_hex_bonus.c ft_printf_strings_bonus.c \
	ft_printf_utils_numbers_bonus.c ft_printf_utils_hex_bonus.c ft_printf_utils_str_bonus.c \
	ft_padding_bonus.c ft_padding_utils_bonus.c ft_parser_bonus.c)

# Object files
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
OBJB := $(addprefix $(OBJB_DIR)/, $(notdir $(SRCB:.c=.o)))

# **************************************************************************** #
#                                COMPILATION                                   #
# **************************************************************************** #

# Default target to create the library
all: $(NAME)

# Create the standard library
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(BGRN)Library $(NAME) created successfully!$(D)"

# Create the bonus library
bonus: clean $(OBJB)
	@ar rcs $(NAME) $(OBJB)
	@echo "$(BGRN)Bonus library $(NAME) created successfully!$(D)"

# Compile standard object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BYEL)Compiled:$(D) $<"

# Compile bonus object files
$(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c
	@mkdir -p $(OBJB_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BYEL)Compiled (Bonus):$(D) $<"

# Remove object files
clean:
	@rm -rf $(OBJ_DIR) $(OBJB_DIR)
	@echo "$(BRED)Object files cleaned!$(D)"

# Remove all generated files
fclean: clean
	@rm -f $(NAME)
	@echo "$(BRED)All cleaned up!$(D)"

# Rebuild everything
re: fclean all

# Declare phony targets to avoid conflicts
.PHONY: all bonus clean fclean re

# **************************************************************************** #
#                                  UTILS                                       #
# **************************************************************************** #

# Colors
B   := $(shell tput bold)
BRED := $(shell tput setaf 9)
BGRN := $(shell tput setaf 10)
BYEL := $(shell tput setaf 11)
D := $(shell tput sgr0)
