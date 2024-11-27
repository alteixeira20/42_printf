# Variables
NAME = ft_printf_tester
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTPRINTF = ../libftprintf.a
SRC = tester.c
OBJ = $(SRC:.c=.o)
RESULT_FILE = results.txt

# Colors
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
ORANGE = \033[38;5;214m

# Default rule
all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(ORANGE)Compiling$(NC) tester.c with libftprintf.a\n"
	@rm -f $(RESULT_FILE) # Remove old results.txt only during recompilation
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L.. -lftprintf

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

run: fclean all
	@./$(NAME)
	@printf "$(ORANGE)Generating test results$(NC) into $(GREEN)results.txt$(NC)\n"
	@printf "\n$(ORANGE)Simplified results:$(NC)\n"
	@awk ' \
		/^-/ { \
			test_name = $$0; getline; \
			printf_line = $$0; getline; \
			ft_printf_line = $$0; \
			# Remove "ft_" prefix from ft_printf_line for comparison \
			sub(/^-- ft_/, "-- ", ft_printf_line); \
			# Compare the modified ft_printf_line with printf_line \
			if (printf_line == ft_printf_line) \
				printf "%s $(GREEN)[OK]$(NC)\n", test_name; \
			else \
				printf "%s $(RED)[KO]$(NC)\n", test_name; \
		}' \
		$(RESULT_FILE)
	@printf "\nTo see more $(GREEN)details$(NC) about specific tests read $(GREEN)results.txt$(NC)\n"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
