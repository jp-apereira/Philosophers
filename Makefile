# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 10:24:03 by jalves-p          #+#    #+#              #
#    Updated: 2024/01/18 13:13:15 by joaopereira      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#.SILENT:

# Color variables
RED = \033[1;31m
GREEN = \033[1;32m
WHITE = \033[1;37m
RESET = \033[0m

# Executable name
NAME = philo

# Compiler options
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g #-fsanitize=thread

# Source and object files
SRCS =	routine.c checks.c main.c settings.c ft_utils.c

OBJS = $(SRCS:.c=.o)

# Default target
$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Build executable
all: $(NAME)

# Clean object files
clean:
	rm -f $(OBJS)

# Clean object files and the executable
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

# Rebuild the project and remove object files
run: re
	$(MAKE) clean
#	./$(NAME) 5 800 200 200
#	./$(NAME) 5 800 200 200 7 | grep eating | wc -l # out: 35
#	./$(NAME) 4 410 200 200 # no one dies
	./$(NAME) 5 410 200 200 # one dies
#	./$(NAME) 3 310 200 100 # one dies

leak: re
	$(MAKE) clean
	valgrind ./$(NAME) 5 800 200 200 5

# Show help message
help:
	echo "\\nUsage: make [target]"
	echo ""
	echo "Targets:"
	echo "  all        Build executable"
	echo "  clean      Remove object files"
	echo "  fclean     Remove object files and executable"
	echo "  re         Rebuild project"
	echo "  run        Rebuild, remove object files and run the program"
