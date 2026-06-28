/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:19:27 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/28 19:14:33 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_value(t_data *data)
{
	t_stack_node	*current;
	t_stack_node	*smallest;

	current = data->a;
	smallest = current;
	while (current)
	{
		if (current->value < smallest->value)
			smallest = current;
		current = current->next;
	}
	return (smallest->value);
}

static int	get_index(t_stack_node *current, int value)
{
	int				index;

	index = 0;
	while (current)
	{
		if (current->value == value)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

void	ft_solve_simple(t_data *data)
{
	int	min_value;
	int	index;

	while (data->a)
	{
		min_value = get_min_value(data);
		index = get_index(data->a, min_value);
		if (index <= ft_lstsize(data->a) / 2)
		{
			while (data->a->value != min_value)
				ft_ra(data);
		}
		else
		{
			while (data->a->value != min_value)
				ft_rra(data);
		}
		ft_pb(data);
	}
	while (data->b)
		ft_pa(data);
}
