# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/04 22:32:48 by ilopez-g          #+#    #+#              #
#    Updated: 2026/06/28 18:48:08 by ilopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = ft_bench.c ft_data.c ft_flags.c ft_printf.c ft_solve.c ft_stack.c push_swap.c ft_lst.c ft_printv.c ft_split.c ft_str.c ft_push.c ft_rotate.c ft_rev_rotate.c ft_swap.c ft_solve_simple.c ft_solve_complex.c ft_solve_medium.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME) Makefile push_swap.h

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test1: all
	./push_swap 5 4 3 2 1

test2: all
	./push_swap $(shell shuf -i 1-100 -n 100)

.PHONY: all clean fclean re
