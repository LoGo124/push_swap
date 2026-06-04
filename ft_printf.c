/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 10:11:42 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/04 22:51:28 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_printv(int fd, char const *str, va_list args)
{
	void	*ptr;

	if (*str == '%' && *(str + 1) == 's')
		return (ft_putstr(fd, va_arg(args, char *)));
	else if (*str == '%' && *(str + 1) == 'c')
		return (ft_putchar(fd, va_arg(args, int)));
	else if (*str == '%' && *(str + 1) == 'i')
		return (ft_putnbr_base(fd, va_arg(args, int), "0123456789"));
	else if (*str == '%' && *(str + 1) == 'd')
		return (ft_putnbr_base(fd, va_arg(args, int), "0123456789"));
	else if (*str == '%' && *(str + 1) == 'u')
		return (ft_putunbr_base(fd, va_arg(args, unsigned), "0123456789"));
	else if (*str == '%' && *(str + 1) == 'x')
		return (ft_putunbr_base(fd, va_arg(args, unsigned), \
"0123456789abcdef"));
	else if (*str == '%' && *(str + 1) == 'X')
		return (ft_putunbr_base(fd, va_arg(args, unsigned), \
"0123456789ABCDEF"));
	else if (*str == '%' && *(str + 1) == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr)
			return (ft_putstr(fd, "0x") + \
ft_putunbr_base(fd, (long)ptr, "0123456789abcdef"));
		return (ft_putstr(fd, "(nil)"));
	}
	return (0);
}

int	ft_printf(int fd, char const *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
			count += ft_putchar(str[i++], fd);
		else if (str[i] == '%')
			count += ft_printv(fd, str + i++, args);
		else
			count += ft_putchar(str[i], fd);
	}
	return (count);
}
