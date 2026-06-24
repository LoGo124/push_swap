/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreyes-m <mreyes-m@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 20:22:39 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/16 17:36:08 by mreyes-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack_node **node)
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
}

void	ft_sa(t_data *data)
{
	ft_swap(&data->a);
	write(1, "sa\n", 3);
	data->bench->sa++;
	data->bench->total_ops++;
}

void	ft_sb(t_data *data)
{
	ft_swap(&data->b);
	write(1, "sb\n", 3);
	data->bench->sb++;
	data->bench->total_ops++;
}

void	ft_ss(t_data *data)
{
	ft_swap(&data->a);
	ft_swap(&data->b);
	write(1, "ss\n", 3);
	data->bench->ss++;
	data->bench->total_ops++;
}
