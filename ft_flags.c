/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:17:40 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/30 18:14:31 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_flags(t_data *data)
{
	data->flags = malloc(sizeof(t_flags));
	if (!data->flags)
		ft_exit(data);
	data->flags->bench = 0;
	data->flags->silence = 0;
	data->flags->adapt = 0;
	data->flags->simple = 0;
	data->flags->medium = 0;
	data->flags->complex = 0;
}

int	is_flag(char *str)
{
	if (!ft_memcmp(str, "--silence", 9))
		return (1);
	else if (!ft_memcmp(str, "--bench", 7))
		return (1);
	else if (!ft_memcmp(str, "--adaptive", 10))
		return (1);
	else if (!ft_memcmp(str, "--simple", 8))
		return (1);
	else if (!ft_memcmp(str, "--medium", 9))
		return (1);
	else if (!ft_memcmp(str, "--complex", 9))
		return (1);
	return (0);
}

static int	ft_check_flags(t_flags *flags)
{
	int	i;

	i = flags->adapt + flags->simple + flags->medium + flags->complex;
	if (i > 1 || flags->bench > 1)
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
	i = -1;
	while (av[++i])
	{
		if (!ft_memcmp(av[i], "--silence", 9))
			data->flags->silence += 1;
		else if (!ft_memcmp(av[i], "--bench", 7))
			data->flags->bench += 1;
		else if (!ft_memcmp(av[i], "--adaptive", 10))
			data->flags->adapt += 1;
		else if (!ft_memcmp(av[i], "--simple", 8))
			data->flags->simple += 1;
		else if (!ft_memcmp(av[i], "--medium", 9))
			data->flags->medium += 1;
		else if (!ft_memcmp(av[i], "--complex", 9))
			data->flags->complex += 1;
	}
	if (!ft_check_flags(data->flags))
		ft_exit(data);
}
