/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:03:05 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/07/05 14:47:52 by ilopez-g         ###   ########.fr       */
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

static t_stack_node	*find_highest_node(t_stack_node *node)
{
	t_stack_node	*highest;
	t_stack_node	*current;

	highest = node;
	current = node;
	while (current)
	{
		if (current->value > highest->value)
			highest = current;
		current = current->next;
	}
	return (highest);
}

static t_stack_node	*find_lowest_node(t_stack_node *node)
{
	t_stack_node	*lowest;
	t_stack_node	*current;

	lowest = node;
	current = node;
	while (current)
	{
		if (current->value < lowest->value)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}

static void	tiny_sort(t_data *data)
{
	t_stack_node	*node;

	if (!(data->a) || ft_lstsize(data->a) <= 1)
		return ;
	if (ft_lstsize(data->a) == 2)
		ft_sa(data);
	else if (ft_lstsize(data->a) == 3)
	{
		node = find_highest_node(data->a);
		if ((data->a) == node)
			ft_ra(data);
		else if ((data->a)->next == node)
			ft_rra(data);
		if ((data->a)->value > (data->a)->next->value)
			ft_sa(data);
	}
	else if (ft_lstsize(data->a) > 3)
	{
		node = find_lowest_node(data->a);
		while ((data->a) != node)
			ft_ra(data);
		ft_pb(data);
		tiny_sort(data);
		ft_pa(data);
	}
}

void	ft_solve(t_data *data)
{
	if (is_sorted(data->a))
		return ;
	if (ft_lstsize(data->a) <= 8)
		tiny_sort(data);
	else
	{
		if (data->flags->simple)
			ft_solve_simple(data);
		else if (data->flags->medium)
			ft_solve_medium(data);
		else if (data->flags->complex)
			ft_solve_complex(data);
	}
}
