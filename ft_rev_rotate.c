/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 20:24:17 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/28 19:34:15 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rev_rotate(t_stack_node **node)
{
	t_stack_node	*last_node;

	if (!node || !*node || !(*node)->next)
		return ;
	last_node = ft_find_last_node(*node);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = *node;
	(*node)->prev = last_node;
	*node = last_node;
}

void	ft_rra(t_data *data)
{
	ft_rev_rotate(&data->a);
	if (!data->flags->silence)
		write(1, "rra\n", 4);
	data->bench->rra++;
	data->bench->total_ops++;
}

void	ft_rrb(t_data *data)
{
	ft_rev_rotate(&data->b);
	if (!data->flags->silence)
		write(1, "rrb\n", 4);
	data->bench->rrb++;
	data->bench->total_ops++;
}

void	ft_rrr(t_data *data)
{
	ft_rev_rotate(&data->a);
	ft_rev_rotate(&data->b);
	if (!data->flags->silence)
		write(1, "rrr\n", 4);
	data->bench->rrr++;
	data->bench->total_ops++;
}
