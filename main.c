/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreyes-m <mreyes-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 08:39:23 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/01 08:40:43 by mreyes-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
    t_stack_node	*a;
    t_stack_node	*b;
    char            **v;

    a = NULL;
    b = NULL;
    v = NULL;
    if (argc < 2)
        return (0);
    
    printf("%p Pointer at the begining of the program\n", (void *)&a);

    v = ft_split(argv[1], ' ');
    stack_fill(&a, v);
    free_split(v);
    while (a)
    {
        printf("%d Content of the node\n", a->value);
        printf("%p Pointer in the loop\n", (void *)**a);
        a = a->next;
    }
    free_stack(&a);
    free_stack(&b);
    return (0);
}




