/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 08:30:42 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/17 12:21:11 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve_complex(t_data *data)
{
	int	iterations;
	int	i;

	i = 1;
	while (!is_sorted(data->a))
	{
		iterations = -1;
		while (++iterations < ft_lstsize(data->a))
		{
			if ((find_first_node(data->a)->value & i
					&& find_first_node(data->a)->value >= 0)
				|| ((find_first_node(data->a)->value & i) == 0
					&& find_first_node(data->a)->value < 0))
				ft_pb(data);
			else
				ft_ra(data);
		}
		while (ft_lstsize(data->b) > 0)
			ft_pa(data);
		i *= 2;
	}
}
