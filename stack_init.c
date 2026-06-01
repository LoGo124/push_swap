/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreyes-m <mreyes-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 10:32:13 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/01 10:34:30 by mreyes-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_fill(t_stack_node **a, char **v)
{
    int i;

    i = 0;
    while (v[i])
    {
        append_node(a, ft_atoi(v[i]));
        i++;
    }
    //ft_printf("%p Pointer at the end of stack_fill\n", (void *)a);
    ft_printf("%d Value of the first node in stack_fill\n", (*a)->value);
    //ft_printf("%p Pointer to the first node in stack_fill\n", (void *)(*a));
    //ft_printf("%p Pointer to the last node in stack_fill\n", (void *)(find_last_node(*a)));
    ft_printf("%d Value of the last node in stack_fill\n", find_last_node(*a)->value);

}

void	free_split(char **v)
{
    int i;

    i = 0;
    while (v[i])
    {
        free(v[i]);
        i++;
    }
    free(v);
}

void    free_stack(t_stack_node **stack)
{
    t_stack_node	*temp;

    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

void    append_node(t_stack_node **stack, int value)
{
    t_stack_node    *new_node;
    t_stack_node	*last_node;

    if (!stack)
        return ;    

    new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (!new_node)
        return ;
    new_node->value = value;
    new_node->next = NULL;
    if (*stack == NULL)
    {
        *stack = new_node;
        new_node->prev = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node->next = new_node;
        new_node->prev = last_node;
    }
}