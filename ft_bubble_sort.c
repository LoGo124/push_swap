/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 08:53:31 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/03 15:58:27 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list    *ft_bubble_sort(t_list *head)
{
	t_list	*current;
	int		swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = head;
		while (current && current->next)
		{
			if (current->value > current->next->value)
			{
				ft_swap(&current);
				swapped = 1;
			}
			current = current->next;
		}
	}
	return (head);
}