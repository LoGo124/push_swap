/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:17:40 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/04 22:50:08 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_flags(t_data *data)
{
	data->flags = malloc(sizeof(t_flags));
	if (!data->flags)
		ft_exit(data);
	data->flags->bench = 0;
	data->flags->verbose = 0;
	data->flags->adapt = 0;
	data->flags->simple = 0;
	data->flags->medium = 0;
	data->flags->complex = 0;
}

int	ft_is_flag(char *str)
{
	if (!ft_memcmp(str, "--verbose", 9))
		return (1);
	if (!ft_memcmp(str, "--benchmark", 11))
		return (1);
	if (!ft_memcmp(str, "--adaptative", 12))
		return (1);
	if (!ft_memcmp(str, "--simple", 8))
		return (1);
	if (!ft_memcmp(str, "--intermediate", 14))
		return (1);
	if (!ft_memcmp(str, "--complex", 9))
		return (1);
	return (0);
}

int	ft_check_flags(t_flags *flags)
{
	int	i;

	i = flags->adapt + flags->simple + flags->medium + flags->complex;
	if (i > 1)
		return (0);
	else if (i == 0)
		flags->adapt = 1;
	return (1);
}

void	ft_load_flags(t_data *data, char **av)
{
	int		i;

	if (!data->flags)
		ft_exit(data);
	i = 0;
	while (av[++i])
	{
		if (!ft_memcmp(av[i], "--verbose", 9))
			data->flags->verbose += 1;
		if (!ft_memcmp(av[i], "--bench", 11))
			data->flags->bench += 1;
		if (!ft_memcmp(av[i], "--adaptative", 12))
			data->flags->adapt += 1;
		if (!ft_memcmp(av[i], "--simple", 8))
			data->flags->simple += 1;
		if (!ft_memcmp(av[i], "--intermediate", 14))
			data->flags->medium += 1;
		if (!ft_memcmp(av[i], "--complex", 9))
			data->flags->complex += 1;
	}
	if (!ft_check_flags(data->flags))
		ft_exit(data);
}
