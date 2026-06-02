/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:12:35 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/02 13:52:22 by ilopez-g         ###   ########.fr       */
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
	data->flags = ft_init_flags();
	if (!data->flags)
	{
		free(data);
		return (NULL);
	}
	return (data);
}

t_data	*ft_parse(int ac, char **av)
{
	t_data	*data;

	if (ac < 2)
		return (NULL);
	data = ft_init_data();
	if (!data)
		return (NULL);
	if (!ft_load_flags(data, av))
		return (NULL);
	return (data);
}
