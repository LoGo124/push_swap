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
	char			**v;
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	v = NULL;
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_printf("%p Pointer at the begining of the program\n", (void *)&a);

	v = ft_split(argv[1], ' ');
	stack_fill(&a, v);
	free_split(v);
	free_stack(&a);
	free_stack(&b);
	return (0);
}




