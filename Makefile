# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalves-p <jalves-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 10:24:03 by jalves-p          #+#    #+#              #
#    Updated: 2024/01/15 17:03:29 by jalves-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = main.c\
		
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -Iinc/
MLXFLAGS = -lXext -lX11 -lm -lz

NAME = philo

all: $(NAME) 

.PHONY: all, fclean, re

$(NAME): $(OBJS)
		cc $(FLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all