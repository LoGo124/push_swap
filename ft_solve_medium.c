/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 08:04:24 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/28 19:16:07 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	found_chunk_size(int size)
{
	if (size <= 50)
		return (10);
	if (size <= 100)
		return (20);
	if (size <= 200)
		return (25);
	if (size <= 500)
		return (40);
	return (45);
}

static int	get_index(t_stack_node *current, int target_index)
{
	int				pos;

	pos = 0;
	while (current)
	{
		if (current->index == target_index)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

static void	push_back_to_a(t_data *data)
{
	int	max_index;
	int	pos;

	while (data->b)
	{
		max_index = (ft_lstsize(data->b) - 1);
		pos = get_index(data->b, max_index);
		if (pos <= ft_lstsize(data->b) / 2)
		{
			while (data->b->index != max_index)
				ft_rb(data);
		}
		else
		{
			while (data->b->index != max_index)
				ft_rrb(data);
		}
		ft_pa(data);
	}
}

static void	push_and_rotate_b(t_data *data, int chunk_max, int chunk_min)
{
	while (data->a)
	{
		if (data->a->index <= chunk_min)
		{
			ft_pb(data);
			ft_rb(data);
			chunk_min++;
		}
		else if (data->a->index <= chunk_max)
		{
			ft_pb(data);
			if (chunk_max % 2 == 0)
				chunk_min++;
			chunk_max++;
		}
		else
			ft_ra(data);
	}
}

void	ft_solve_medium(t_data *data)
{
	int	chunk_max;
	int	chunk_min;

	chunk_max = found_chunk_size(ft_lstsize(data->a));
	chunk_min = 0;
	ft_assign_indices(data->a);
	push_and_rotate_b(data, chunk_max, chunk_min);
	push_back_to_a(data);
}
