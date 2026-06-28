/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:29:37 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/28 18:13:36 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = NULL;
	data->b = NULL;
	ft_init_flags(data);
	ft_init_bench(data);
	return (data);
}

void	free_data(t_data *data)
{
	if (data)
	{
		if (data->a)
			free_stack(&data->a);
		if (data->b)
			free_stack(&data->b);
		if (data->flags)
			free(data->flags);
		if (data->bench)
			free(data->bench);
		free(data);
	}
}
