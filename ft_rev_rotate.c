/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 20:24:17 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/11 09:17:12 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stack_node **node)
{
	t_stack_node	*last_node;

	if (!node || !*node || !(*node)->next)
		return ;
	last_node = find_last_node(*node);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = *node;
	(*node)->prev = last_node;
	*node = last_node;
}

void	ft_rra(t_data *data)
{
	ft_rev_rotate(&data->a);
	write(1, "rra\n", 4);
	data->bench->rra++;
}

void	ft_rrb(t_data *data)
{
	ft_rev_rotate(&data->b);
	write(1, "rrb\n", 4);
	data->bench->rrb++;
}

void	ft_rrr(t_data *data)
{
	ft_rev_rotate(&data->a);
	ft_rev_rotate(&data->b);
	write(1, "rrr\n", 4);
	data->bench->rrr++;
}
