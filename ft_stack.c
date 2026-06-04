/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:41:41 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/04 19:50:31 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_stack(t_data *data)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		ft_exit(data);
	stack->top = NULL;
	stack->bot = NULL;
	stack->size = 0;
	return (stack);
}

void	ft_load_stack(t_data *data, char **av)
{
	stack_fill(&data->a->top, av);
	data->a->bot = find_last_node(data->a->top);
	while (data->a->top)
	{
		data->a->size++;
		data->a->top = data->a->top->next;
	}
}

void	stack_fill(t_stack_node **a, char **v)
{
	int	i;

	i = 0;
	while (v[i])
	{
		append_node(a, ft_atoi(v[i]));
		i++;
	}
	//ft_printf("%p Pointer at the end of stack_fill\n", (void *)a);
	ft_printf("%d Value of the first node in stack_fill\n", (*a)->value);
	//ft_printf("%p Pointer to the first node in stack_fill\n", (void *)(*a));
	//ft_printf("%p Pointer to the last node in stack_fill\n", (void *)(find_last_node(*a)));
	ft_printf("%d Value of the last node in stack_fill\n", find_last_node(*a)->value);

}

void	append_node(t_stack_node **node, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!node)
		return ;
	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (*node == NULL)
	{
		*node = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*node);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
