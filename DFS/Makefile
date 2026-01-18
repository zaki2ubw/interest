# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/18 19:25:02 by sohyamaz          #+#    #+#              #
#    Updated: 2026/01/18 19:39:38 by sohyamaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dfs_test
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	   phase00.c \
	   phase01.c \
	   phase02.c \
	   phase03.c \
	   phase04.c \
	   phase05.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

#Phony target declaration
.PHONY	: all re clean fclean
