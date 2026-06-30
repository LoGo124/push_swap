# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/04 22:32:48 by ilopez-g          #+#    #+#              #
#    Updated: 2026/06/30 15:56:45 by ilopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
SRCS = ft_bench.c ft_data.c ft_flags.c ft_printf.c ft_solve.c ft_stack.c push_swap.c ft_lst.c ft_printv.c ft_split.c ft_str.c ft_push.c ft_rotate.c ft_rev_rotate.c ft_swap.c ft_solve_simple.c ft_solve_complex.c ft_solve_medium.c
OBJS = $(SRCS:.c=.o)
CHECKER_SRCS = checker.c ft_gnl.c ft_gnl_utils.c $(filter-out push_swap.c,$(SRCS))
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
SIZE ?= 100
SIZES ?= 25 50 100 250 500 1000 2000
NUMBERS_FILE ?= NUMBERS.txt
FLAGS ?=
CHECKER_FLAGS ?=

all: $(NAME) $(CHECKER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(CHECKER): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER)

%.o: %.c push_swap.h checker.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(CHECKER_OBJS)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

aclean: fclean
	$(RM) $(NUMBERS_FILE)

re: fclean all

$(NUMBERS_FILE):
	@echo "Generating $(SIZE) random values in $(NUMBERS_FILE)"
	@shuf -i 0-999999 -n $(SIZE) > $(NUMBERS_FILE)

gen:
	@$(MAKE) --no-print-directory $(NUMBERS_FILE)

test_%:
	@$(MAKE) --no-print-directory test SIZE=$*

check_%:
	@$(MAKE) --no-print-directory check SIZE=$*

test: $(NAME) $(NUMBERS_FILE)
	@./$(NAME) $$(cat $(NUMBERS_FILE)) $(FLAGS)

check: $(NAME) $(CHECKER) $(NUMBERS_FILE)
	@./$(NAME) $$(cat $(NUMBERS_FILE)) $(FLAGS) | ./$(CHECKER) $$(cat $(NUMBERS_FILE)) $(CHECKER_FLAGS)

test_all:
	@for n in $(SIZES); do \
		echo "==> size $$n"; \
		$(MAKE) --no-print-directory test SIZE=$$n FLAGS="$(FLAGS)" || exit 1; \
	done

check_all:
	@for n in $(SIZES); do \
		echo "==> checker size $$n"; \
		$(MAKE) --no-print-directory check SIZE=$$n FLAGS="$(FLAGS)" CHECKER_FLAGS="$(CHECKER_FLAGS)" || exit 1; \
	done

bench: FLAGS += --bench
bench: test_all

silence: FLAGS += --silence
silence: test_all

adapt: FLAGS += --adaptative
adapt: test_all

simple: FLAGS += --simple
simple: test_all

medium: FLAGS += --intermediate
medium: test_all

complex: FLAGS += --complex
complex: test_all

.PHONY: all clean fclean re aclean gen test check test_all check_all bench silence adapt simple medium complex
