/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 08:39:23 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/07/04 12:38:45 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*parse(int ac, char **av)
{
	t_data	*data;

	if (ac < 2)
		return (NULL);
	data = ft_init_data();
	ft_load_flags(data, av);
	ft_load_stack(data, av);
	return (data);
}

void	calc_disorder(t_data *data)
{
	t_stack_node	*current_node;
	t_stack_node	*compared_node;
	int				total_pairs;
	int				disordered_pairs;
	int				size;

	size = ft_lstsize(data->a);
	if (!data->a || size < 2)
		return ;
	current_node = data->a;
	total_pairs = 0;
	disordered_pairs = 0;
	while (current_node)
	{
		compared_node = current_node->next;
		while (compared_node)
		{
			total_pairs++;
			if (current_node->value > compared_node->value)
				disordered_pairs++;
			compared_node = compared_node->next;
		}
		current_node = current_node->next;
	}
	data->bench->disorder = ((double)disordered_pairs / (double)total_pairs);
}

void	select_strategy(t_data *data)
{
	if (data->bench->disorder < 0.2 || ft_lstsize(data->a) < 12)
		data->flags->simple = 1;
	else if (data->bench->disorder < 0.5)
		data->flags->medium = 1;
	else
		data->flags->complex = 1;
}

void	ft_exit(t_data *data)
{
	free_data(data);
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = parse(ac, &av[1]);
	calc_disorder(data);
	if (data->flags->adapt)
		select_strategy(data);
	ft_update_bench(data);
	ft_solve(data);
	if (data->flags->bench)
		ft_print_bench(data->bench);
	free_data(data);
	return (0);
}
