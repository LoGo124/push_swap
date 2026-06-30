/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 16:55:52 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/30 17:46:10 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_exit(t_data *data)
{
	free_data(data);
	write(2, "Error\n", 6);
	exit(1);
}

static void	load_stack(t_data *data, char **av)
{
	int		i;
	long	curr_n;
	char	**splited_arg;

	i = -1;
	while (av[++i])
	{
		curr_n = ft_atoi(av[i]);
		if (curr_n < -2147483648 || curr_n >= 2147483648)
			ft_exit(data);
		else if (is_number(av[i]))
			ft_append_node(&data->a, ft_atoi(av[i]));
		else
		{
			splited_arg = ft_split(av[i], ' ');
			if (!splited_arg)
				ft_exit(data);
			ft_stack_fill(data, splited_arg);
			free_split(splited_arg);
		}
	}
	if (!ft_check_stack(data->a))
		ft_exit(data);
}

void	exec_move(t_data *data, char *line)
{
	if (!ft_memcmp(line, "sa\n", 3))
		ft_sa(data);
	else if (!ft_memcmp(line, "sb\n", 3))
		ft_sb(data);
	else if (!ft_memcmp(line, "ss\n", 3))
		ft_ss(data);
	else if (!ft_memcmp(line, "ra\n", 3))
		ft_ra(data);
	else if (!ft_memcmp(line, "rb\n", 3))
		ft_rb(data);
	else if (!ft_memcmp(line, "rr\n", 3))
		ft_rr(data);
	else if (!ft_memcmp(line, "rra\n", 4))
		ft_rra(data);
	else if (!ft_memcmp(line, "rrb\n", 4))
		ft_rrb(data);
	else if (!ft_memcmp(line, "rrr\n", 4))
		ft_rrr(data);
	else if (!ft_memcmp(line, "pa\n", 3))
		ft_pa(data);
	else if (!ft_memcmp(line, "pb\n", 3))
		ft_pb(data);
	else
		ft_exit(data);
}

void	read_exec(t_data *data)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		exec_move(data, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac < 2)
		return (0);
	data = ft_init_data();
	load_stack(data, &av[1]);
	data->flags->silence = 1;
	read_exec(data);
	if ((data->a == NULL || is_sorted(data->a)) && data->b == NULL)
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
	free_data(data);
	return (0);
}
