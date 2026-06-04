/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:35:12 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/03 15:42:10 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **v)
{
	int	i;

	i = 0;
	while (v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
}

void	free_stack(t_stack_node **node)
{
	t_stack_node	*temp;

	while (*node)
	{
		temp = *node;
		*node = (*node)->next;
		free(temp);
	}
}

void	_free_stack_(t_stack *stack)
{
	t_stack_node	*node;
	t_stack_node	*temp;

	node = stack->top;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
}

void	free_data(t_data *data)
{
	if (data)
	{
		if (data->a)
			_free_stack_(data->a);
		if (data->b)
			_free_stack_(data->b);
		if (data->flags)
			free(data->flags);
		if (data->bench)
			free(data->bench);
		free(data);
	}
}

void	ft_exit(t_data *data)
{
	free_data(data);
	write(2, "Error\n", 6);
	exit(1);
}
