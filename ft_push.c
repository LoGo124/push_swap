/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreyes-m <mreyes-m@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 20:20:56 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/16 17:06:25 by mreyes-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*node_pushed;

	if (!src || !*src)
		return ;
	node_pushed = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_pushed->prev = NULL;
	node_pushed->next = *dest;
	if (*dest)
		(*dest)->prev = node_pushed;
	*dest = node_pushed;
}

void	ft_pb(t_data *data)
{
	ft_push(&data->a, &data->b);
	write(1, "pb\n", 3);
	data->bench->pb++;
	data->bench->total_ops++;
}

void	ft_pa(t_data *data)
{
	ft_push(&data->b, &data->a);
	write(1, "pa\n", 3);
	data->bench->pa++;
	data->bench->total_ops++;
}
