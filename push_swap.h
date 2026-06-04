/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 08:29:42 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/04 22:48:34 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

// To delete
//# include <stdio.h>

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*top;
	t_stack_node	*bot;
	int				size;
}	t_stack;

typedef struct s_flags
{
	int	bench;
	int	verbose;
	int	adapt;
	int	simple;
	int	medium;
	int	complex;
}	t_flags;

typedef struct s_bench
{
	double	disorder;
	char	*strategy;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	t_flags	*flags;
	t_bench	*bench;
}	t_data;

// ft_str.c
char			**ft_split(char const *s, char c);

t_stack_node	*find_last_node(t_stack_node *head);
void			free_split(char **v);
void			free_stack(t_stack_node **stack);
void			append_node(t_stack_node **stack, int value);
void			ft_exit(t_data *data);
void			stack_fill(t_stack_node **a, char **v);

// ft_parse.c
t_data			*ft_parse(int ac, char **av);

// ft_flag.c
void			ft_init_flags(t_data *data);
void			ft_load_flags(t_data *data, char **av);
int				ft_is_flag(char *str);

// ft_str.c
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_atoi(const char *nptr);

// ft_bench.c
void			ft_init_bench(t_data *data);
void			ft_print_bench(t_bench *bench);

// ft_data.c
t_data			*ft_init_data(void);

// ft_stack.c
t_stack			*ft_init_stack(t_data *data);
void			ft_load_stack(t_data *data, char **av);

// ft_printf.c & ft_puval.c
int				ft_putchar(int fd, char c);
int				ft_putstr(int fd, char *str);
int				ft_putnbr_base(int fd, long int nbr, char *base);
int				ft_putunbr_base(int fd, unsigned long int nbr, char *base);
int				ft_printf(int fd, char const *str, ...);

// lst

// ft_free.c
void			free_split(char **v);
void			free_stack(t_stack_node **stack);
void			_free_stack_(t_stack *stack);
void			free_data(t_data *data);
void			ft_exit(t_data *data);

// ft_operations.c
void			ft_swap(t_stack_node **stack);
void			ft_push(t_stack_node **src, t_stack_node **dest);
void			ft_rotate(t_stack_node **stack);
void			ft_rev_rotate(t_stack_node **stack);

// ft_solve.c
void			ft_solve(t_data *data);

#endif
