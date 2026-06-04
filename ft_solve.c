/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:03:05 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/04 22:32:18 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack_node	*node;

	if (!stack || stack->size < 2)
		return (1);
	node = stack->top;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	ft_calc_disorder(t_data *data)
{
	t_stack_node	*current_node;
	t_stack_node	*compared_node;
	int				total_pairs;
	int				disordered_pairs;

	if (!data->a || data->a->size < 2)
		return ;
	current_node = data->a->top;
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

void	ft_select_strategy(t_data *data)
{
	if (data->bench->disorder < 0.2)
	{
		data->bench->strategy = "Simple";
		data->flags->simple = 1;
	}
	else if (data->bench->disorder < 0.5)
	{
		data->bench->strategy = "Intermediate";
		data->flags->medium = 1;
	}
	else
	{
		data->bench->strategy = "Complex";
		data->flags->complex = 1;
	}
}

void	ft_solve(t_data *data)
{
	ft_calc_disorder(data);
	if (is_sorted(data->a))
		return ;
	if (data->flags->adapt)
		ft_select_strategy(data);
	if (data->flags->simple)
		ft_printf(1, "Simple\n");//ft_solve_simple(data);
	else if (data->flags->medium)
		ft_printf(1, "Medium\n");//ft_solve_medium(data);
	else if (data->flags->complex)
		ft_printf(1, "Complex\n");//ft_solve_complex(data);
}