/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 08:30:42 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/28 19:20:13 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack_node *node)
{
	int				*array;
	int				i;
	t_stack_node	*current;

	i = 0;
	current = node;
	array = malloc(ft_lstsize(node) * sizeof(int));
	if (!array)
		return (NULL);
	while (current)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	return (array);
}

static void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_assign_indices(t_stack_node *current)
{
	int				*array;
	int				size;
	int				i;

	size = ft_lstsize(current);
	array = stack_to_array(current);
	bubble_sort(array, size);
	while (current)
	{
		i = -1;
		while (++i < size)
		{
			if (current->value == array[i])
			{
				current->index = i;
				break ;
			}
		}
		current = current->next;
	}
	free(array);
}

void	ft_solve_complex(t_data *data)
{
	int	iterations;
	int	size;
	int	i;

	i = 1;
	size = ft_lstsize(data->a);
	ft_assign_indices(data->a);
	while (!is_sorted(data->a))
	{
		iterations = 0;
		while (iterations < size)
		{
			if ((data->a->index & i) == 0)
				ft_pb(data);
			else
				ft_ra(data);
			iterations++;
		}
		while (ft_lstsize(data->b) > 0)
			ft_pa(data);
		i = i * 2;
	}
}
