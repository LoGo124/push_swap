/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreyes-m <mreyes-m@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:18:47 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/23 12:23:29 by mreyes-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
static t_stack_node *find_highest_node(t_stack_node *node)
{
    t_stack_node *highest;
    t_stack_node *current;

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

static t_stack_node *find_lowest_node(t_stack_node *node)
{
    t_stack_node *lowest;
    t_stack_node *current;

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

void sort_three(t_data *data)
{
    t_stack_node *highest;

    highest = find_highest_node(data->a);
    if ((data->a) == highest)
        ft_ra(data);
    else if((data->a)->next == highest)
        ft_rra(data);
    if ((data->a)->value > (data->a)->next->value)
        ft_sa(data);
}

void sort_four(t_data *data)
{
    t_stack_node *lowest;

    lowest = find_lowest_node(data->a);
    while ((data->a) != lowest)
        ft_ra(data);
    ft_pb(data);
    sort_three(data);
    ft_pa(data);
}

void sort_five(t_data *data)
{
    t_stack_node *lowest;

    lowest = find_lowest_node(data->a);
    while ((data->a) != lowest)
        ft_ra(data);
    ft_pb(data);
    sort_four(data);
    ft_pa(data);
}