/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:27:07 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/02 16:16:17 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr(int fd, char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = 0;
	while (*str)
		len += ft_putchar(fd, *str++);
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

int	ft_putnbr_base(int fd, long int nbr, char *base)
{
	int	count;
	int	c;

	count = 0;
	c = check_base(base);
	if (!c || c == 1)
		return (0);
	if (nbr < 0)
	{
		write(fd, "-", 1);
		count++;
		if (-(nbr / c))
			count += ft_putnbr_base(fd, -(nbr / c), base);
		write(fd, &base[-(nbr % c)], 1);
	}
	else if (nbr < c)
		write(fd, &base[nbr], 1);
	else
	{
		count = ft_putnbr_base(fd, nbr / c, base);
		write(fd, &base[nbr % c], 1);
	}
	return (count + 1);
}

int	ft_putunbr_base(int fd, unsigned long int nbr, char *base)
{
	int				count;
	unsigned int	c;

	count = 0;
	c = check_base(base);
	if (!c || c == 1)
		return (0);
	if (nbr < c)
		write(fd, &base[nbr], 1);
	else
	{
		count = ft_putunbr_base(fd, nbr / c, base);
		write(fd, &base[nbr % c], 1);
	}
	return (count + 1);
}
