/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreyes-m <mreyes-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 08:29:42 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/01 11:54:21 by mreyes-m         ###   ########.fr       */
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
	int	benchmark;
	int verbose;
	int	adaptative;
	int simple;
	int intermediate;
	int complex;
}	t_flags;

char			**ft_split(char const *s, char c);
t_stack_node	*find_last_node(t_stack_node *head);
void			stack_fill(t_stack_node **a, char **v);
void			free_split(char **v);
void			free_stack(t_stack_node **stack);
void			append_node(t_stack_node **stack, int value);
int				ft_atoi(const char *nptr);

// printf
int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_putnbr_base(long int nbr, char *base);
int				ft_putunbr_base(unsigned long int nbr, char *base);
int				ft_printf(char const *str, ...);

// lst

#endif
