/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:18:46 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/28 18:45:54 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack_node *node)
{
	int	size;

	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

t_stack_node	*ft_find_last_node(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_stack_node	*ft_find_first_node(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node->prev)
		node = node->prev;
	return (node);
}

void	ft_append_node(t_stack_node **node, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!node)
		return ;
	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	new_node->index = -1;
	if (*node == NULL)
	{
		*node = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last_node(*node);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
