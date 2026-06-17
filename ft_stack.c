/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:41:41 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/17 11:38:53 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **node, int value)
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
	if (*node == NULL)
	{
		*node = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*node);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	stack_fill(t_data *data, char **v)
{
	int				i;

	i = 0;
	while (v[i])
	{
		if (!ft_is_number(v[i]))
			ft_exit(data);
		append_node(&data->a, ft_atoi(v[i++]));
	}
}

int	check_stack(t_stack_node *node)
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

void	ft_load_stack(t_data *data, char **av)
{
	int		i;
	char	**splited_arg;

	i = -1;
	while (av[++i])
	{
		if (ft_is_number(av[i]))
			append_node(&data->a, ft_atoi(av[i]));
		else if (!ft_is_flag(av[i]))
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
