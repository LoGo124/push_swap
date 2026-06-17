/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 08:39:23 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/11 11:51:08 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_parse(int ac, char **av)
{
	t_data	*data;

	if (ac < 2)
		return (NULL);
	data = ft_init_data();
	ft_load_flags(data, av);
	ft_load_stack(data, av);
	return (data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_parse(ac, &av[1]);
	ft_solve(data);
	if (data->flags->bench)
		ft_print_bench(data->bench);
	free_data(data);
	return (0);
}
