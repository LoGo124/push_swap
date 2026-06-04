/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:49:58 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/04 15:23:51 by ilopez-g         ###   ########.fr       */
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

void	ft_swap(t_stack_node **node)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	if (!node || !*node || !(*node)->next)
		return ;
	*node = (*node)->next;
	first = *node;
	second = (*node)->prev;
	third = (*node)->next;
	first->prev = NULL;
	first->next = second;
	second->prev = first;
	second->next = third;
	if (third)
		third->prev = second;
}

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
