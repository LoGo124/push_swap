/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:27:07 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/05/11 16:36:31 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = 0;
	while (*str)
		len += ft_putchar(*str++);
	return (len);
}

static int	check_base(char *str)
{
	int	c;
	int	i;

	c = 0;
	while (str[c])
	{
		if (str[c] == '+' || str[c] == '-')
			return (0);
		i = c + 1;
		while (str[i])
		{
			if (str[c] == str[i])
				return (0);
			i++;
		}
		c++;
	}
	return (c);
}

int	ft_putnbr_base(long int nbr, char *base)
{
	int	count;
	int	c;

	count = 0;
	c = check_base(base);
	if (!c || c == 1)
		return (0);
	if (nbr < 0)
	{
		write(1, "-", 1);
		count++;
		if (-(nbr / c))
			count += ft_putnbr_base(-(nbr / c), base);
		write(1, &base[-(nbr % c)], 1);
	}
	else if (nbr < c)
		write(1, &base[nbr], 1);
	else
	{
		count = ft_putnbr_base(nbr / c, base);
		write(1, &base[nbr % c], 1);
	}
	return (count + 1);
}

int	ft_putunbr_base(unsigned long int nbr, char *base)
{
	int				count;
	unsigned int	c;

	count = 0;
	c = check_base(base);
	if (!c || c == 1)
		return (0);
	if (nbr < c)
		write(1, &base[nbr], 1);
	else
	{
		count = ft_putunbr_base(nbr / c, base);
		write(1, &base[nbr % c], 1);
	}
	return (count + 1);
}
