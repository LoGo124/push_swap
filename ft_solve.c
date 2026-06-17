/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreyes-m <mreyes-m@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:03:05 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/16 09:30:00 by mreyes-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_node *node)
{
	int				size;

	size = ft_lstsize(node);
	if (!node || size < 2)
		return (1);
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	calc_disorder(t_data *data)
{
	t_stack_node	*current_node;
	t_stack_node	*compared_node;
	int				total_pairs;
	int				disordered_pairs;
	int				size;

	size = ft_lstsize(data->a);
	if (!data->a || size < 2)
		return ;
	current_node = data->a;
	total_pairs = 0;
	disordered_pairs = 0;
	while (current_node)
	{
		compared_node = current_node->next;
		while (compared_node)
		{
			total_pairs++;
			if (current_node->value > compared_node->value)
				disordered_pairs++;
			compared_node = compared_node->next;
		}
		current_node = current_node->next;
	}
	data->bench->disorder = ((double)disordered_pairs / (double)total_pairs);
}

void	select_strategy(t_data *data)
{
	if (data->bench->disorder < 0.2)
	{
		data->bench->strategy = "Adaptative / O(n^2)";
		data->flags->simple = 1;
	}
	else if (data->bench->disorder < 0.5)
	{
		data->bench->strategy = "Adaptative / O(n√n)";
		data->flags->medium = 1;
	}
	else
	{
		data->bench->strategy = "Adaptative / O(n log n)";
		data->flags->complex = 1;
	}
}

void	ft_solve(t_data *data)
{
	calc_disorder(data);
	if (is_sorted(data->a))
		return ;
	if (data->flags->adapt)
		select_strategy(data);
	if (data->flags->simple)
		ft_solve_simple(data);
	else if (data->flags->medium)
		ft_printf(1, "Medium\n");//ft_solve_medium(data);
	else if (data->flags->complex)
		ft_solve_complex(data);
}
