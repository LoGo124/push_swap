/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:27:15 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/11 11:56:31 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
		if (!isdigit(str[i++]))
			return (0);
	return (1);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	c;
	int		diff;

	c = -1;
	diff = 0;
	while (++c < n && !diff)
		diff = *(unsigned char *)(s1 + c) - *(unsigned char *)(s2 + c);
	return (diff);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}
