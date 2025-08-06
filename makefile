# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juanandub <juanandub@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 00:00:00 by juanandub         #+#    #+#              #
#    Updated: 2025/08/06 11:54:20 by juanandub        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = philo

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
DEBUG_FLAGS = -g -fsanitize=thread

# Source files
SRCS = philo.c \
       ft_atoi.c \
       check_args.c  \
       init.c \
       ft_get_current_time.c \
       threads.c \
	   actions.c 

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = philo.h

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[0;33m
NC = \033[0m # No Color

# Default rule
all: $(NAME)

# Compile the program
$(NAME): $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) compiled successfully!$(NC)"

# Compile object files
%.o: %.c $(HEADERS)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Debug version with thread sanitizer
debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean $(NAME)
	@echo "$(BLUE)Debug version compiled with thread sanitizer$(NC)"

# Clean object files
clean:
	@echo "$(RED)Removing object files...$(NC)"
	@rm -f $(OBJS)

# Clean everything
fclean: clean
	@echo "$(RED)Removing $(NAME)...$(NC)"
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

# Test with basic arguments
test: $(NAME)
	@echo "$(BLUE)Running test with basic arguments...$(NC)"
	@./$(NAME) 5 800 200 200

# Help
help:
	@echo "$(GREEN)Available targets:$(NC)"
	@echo "  $(YELLOW)all$(NC)     - Build the program"
	@echo "  $(YELLOW)debug$(NC)   - Build with debug flags and thread sanitizer"
	@echo "  $(YELLOW)clean$(NC)   - Remove object files"
	@echo "  $(YELLOW)fclean$(NC)  - Remove object files and executable"
	@echo "  $(YELLOW)re$(NC)      - Rebuild everything"
	@echo "  $(YELLOW)test$(NC)    - Run basic test"
	@echo "  $(YELLOW)help$(NC)    - Show this help"

# Phony targets
.PHONY: all clean fclean re debug test help
