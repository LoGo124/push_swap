/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 08:29:42 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/28 19:41:12 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_flags
{
	int	bench;
	int	silence;
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
	t_stack_node	*a;
	t_stack_node	*b;
	t_flags			*flags;
	t_bench			*bench;
}	t_data;

// push_swap.c
void			ft_exit(t_data *data);

// ft_data.c
t_data			*ft_init_data(void);
void			free_data(t_data *data);

// ft_stack.c
void			ft_load_stack(t_data *data, char **av);
void			free_stack(t_stack_node **stack);

// ft_flag.c
int				is_flag(char *str);
void			ft_init_flags(t_data *data);
void			ft_load_flags(t_data *data, char **av);

// ft_bench.c
void			ft_init_bench(t_data *data);
void			ft_update_bench(t_data *data);
void			ft_print_bench(t_bench *bench);

// ft_split.c
char			**ft_split(char const *s, char c);
void			free_split(char **v);

// ft_solve.c
int				is_sorted(t_stack_node *node);
void			ft_solve(t_data *data);

// ALGOS: ft_solve_simple.c ft_solve_medium.c ft_solve_complex.c
void			ft_solve_simple(t_data *data);
void			ft_solve_medium(t_data *data);
void			ft_solve_complex(t_data *data);
void			ft_assign_indices(t_stack_node *node);

// MOVEMENTS
// ft_push.c
void			ft_pb(t_data *data);
void			ft_pa(t_data *data);

// ft_swap.c
void			ft_sa(t_data *data);
void			ft_sb(t_data *data);
void			ft_ss(t_data *data);

// ft_rotate.c
void			ft_ra(t_data *data);
void			ft_rb(t_data *data);
void			ft_rr(t_data *data);

// ft_rev_rotate.c
void			ft_rra(t_data *data);
void			ft_rrb(t_data *data);
void			ft_rrr(t_data *data);

// ft_lst.c
int				ft_lstsize(t_stack_node *node);
t_stack_node	*ft_find_last_node(t_stack_node *node);
t_stack_node	*ft_find_first_node(t_stack_node *node);
void			ft_append_node(t_stack_node **stack, int value);

// PRINTF: ft_printf.c & ft_putval.c
int				ft_putchar(int fd, char c);
int				ft_putstr(int fd, char *str);
int				ft_putnbr_base(int fd, long int nbr, char *base);
int				ft_putunbr_base(int fd, unsigned long int nbr, char *base);
int				ft_printf(int fd, char const *str, ...);

// ft_str.c
int				is_number(char *str);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
long			ft_atoi(const char *nptr);

#endif
