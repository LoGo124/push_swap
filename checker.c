/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreyes-m <mreyes-m@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 16:55:52 by mreyes-m          #+#    #+#             */
/*   Updated: 2026/06/28 17:19:01 by mreyes-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_init_data();
	ft_load_stack(data, av);

	execute_instructions(data);

	if (is_sorted(data.a) && data.b == NULL)
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
}

