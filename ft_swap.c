/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 20:22:39 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/30 18:41:55 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack_node **node)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	if (!node || !*node || !(*node)->next)
		return ;
	second = *node;
	first = (*node)->next;
	third = (*node)->next->next;
	first->prev = NULL;
	first->next = second;
	second->prev = first;
	second->next = third;
	if (third)
		third->prev = second;
	*node = first;
}

void	ft_sa(t_data *data)
{
	ft_swap(&data->a);
	if (!data->flags->silence)
		write(1, "sa\n", 3);
	data->bench->sa++;
	data->bench->total_ops++;
}

void	ft_sb(t_data *data)
{
	ft_swap(&data->b);
	if (!data->flags->silence)
		write(1, "sb\n", 3);
	data->bench->sb++;
	data->bench->total_ops++;
}

void	ft_ss(t_data *data)
{
	ft_swap(&data->a);
	ft_swap(&data->b);
	if (!data->flags->silence)
		write(1, "ss\n", 3);
	data->bench->ss++;
	data->bench->total_ops++;
}
