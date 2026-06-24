/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreyes-m <mreyes-m@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 08:30:42 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/23 13:34:28 by mreyes-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int *stack_to_array(t_stack_node *node)
{
	int	*array;
	int	i;
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

static void bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while(i < size - 1)
	{
		j = 0;
		while(j < size - 1 - i)
		{
			if(array[j] > array[j + 1])
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

void ft_assign_indices(t_stack_node *node)
{
	int	*array;
	int	size;
	int	i;
	t_stack_node	*current;

	size = ft_lstsize(node);
	array = stack_to_array(node);
	bubble_sort(array, size);
	current = node;
	while (current)
	{
		i = 0;
		while(i < size)
		{
			if (current->value == array[i])
			{
				current->index = i;
				break;
			}
			i++;
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
			if ((find_first_node(data->a)->index & i) == 0)
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