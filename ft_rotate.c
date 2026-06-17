/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 20:05:14 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/11 09:17:06 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack_node **node)
{
	t_stack_node	*last_node;

	if (!node || !*node || !(*node)->next)
		return ;
	last_node = find_last_node(*node);
	last_node->next = *node;
	(*node) = (*node)->next;
	(*node)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ft_ra(t_data *data)
{
	ft_rotate(&data->a);
	write(1, "ra\n", 3);
	data->bench->ra++;
}

void	ft_rb(t_data *data)
{
	ft_rotate(&data->b);
	write(1, "rb\n", 3);
	data->bench->rb++;
}

void	ft_rr(t_data *data)
{
	ft_rotate(&data->a);
	ft_rotate(&data->b);
	write(1, "rr\n", 3);
	data->bench->rr++;
}
