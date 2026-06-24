/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreyes-m <mreyes-m@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 08:04:24 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/24 12:47:47 by mreyes-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int found_chunk_size(int size)
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

int	get_index_b(t_data *data, int target_index)
{
	t_stack_node	*current;
	int				index;

	current = data->b;
	index = 0;
	while (current)
	{
		if (current->index == target_index)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

int get_max_index (t_data *data)
{
    t_stack_node    *current;
    t_stack_node    *max;

    current = data->b;
    max = current;
    while (current)
    {
        if(current->index > max->index)
            max = current;
        current = current->next;
    }
    return (max->index);
}

void push_and_rotate_b(t_data *data, int chunk_max, int chunk_min)
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
#include <stdio.h>
void ft_solve_medium(t_data *data)
{
    int max_index;
    int pos;
    int chunk_max;
    int chunk_min;
    
    chunk_max = found_chunk_size(ft_lstsize(data->a));
    chunk_min = 0;
    
    ft_assign_indices(data->a);
    push_and_rotate_b(data, chunk_max, chunk_min);
    while (data->b)
    {
        max_index = (ft_lstsize(data->b) - 1);
        pos = get_index_b(data, max_index);
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

