/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:41:41 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/28 19:38:52 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_fill(t_data *data, char **v)
{
	int		i;
	long	curr_n;

	i = 0;
	while (v[i])
	{
		curr_n = ft_atoi(v[i]);
		if (!is_number(v[i]) || curr_n < -2147483648 || curr_n >= 2147483648)
			ft_exit(data);
		ft_append_node(&data->a, ft_atoi(v[i++]));
	}
}

static int	check_stack(t_stack_node *node)
{
	t_stack_node	*compared_node;

	if (!node)
		return (1);
	while (node)
	{
		compared_node = node->next;
		while (compared_node)
		{
			if (node->value == compared_node->value)
				return (0);
			compared_node = compared_node->next;
		}
		node = node->next;
	}
	return (1);
}

void	free_stack(t_stack_node **node)
{
	t_stack_node	*temp;

	while (*node)
	{
		temp = *node;
		*node = (*node)->next;
		free(temp);
	}
}

void	ft_load_stack(t_data *data, char **av)
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
		else if (!is_flag(av[i]))
		{
			splited_arg = ft_split(av[i], ' ');
			if (!splited_arg)
				ft_exit(data);
			stack_fill(data, splited_arg);
			free_split(splited_arg);
		}
	}
	if (!check_stack(data->a))
		ft_exit(data);
}
