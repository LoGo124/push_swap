/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreyes-m <mreyes-m@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:35:41 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/16 14:22:58 by mreyes-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_bench(t_data *data)
{
	data->bench = malloc(sizeof(t_bench));
	if (!data->bench)
		ft_exit(data);
	data->bench->disorder = 0.0;
	data->bench->strategy = NULL;
	data->bench->total_ops = 0;
	data->bench->sa = 0;
	data->bench->sb = 0;
	data->bench->ss = 0;
	data->bench->pa = 0;
	data->bench->pb = 0;
	data->bench->ra = 0;
	data->bench->rb = 0;
	data->bench->rr = 0;
}

void	ft_print_bench(t_bench *bench)
{
	ft_printf(2, "Strategy: %s\n", bench->strategy);
	ft_printf(2, "Disorder: %d%%\n", (int)(bench->disorder * 100));
	ft_printf(2, "Total operations: %d\n", bench->total_ops);
	ft_printf(2, "sa: %d\n", bench->sa);
	ft_printf(2, "sb: %d\n", bench->sb);
	ft_printf(2, "ss: %d\n", bench->ss);
	ft_printf(2, "pa: %d\n", bench->pa);
	ft_printf(2, "pb: %d\n", bench->pb);
	ft_printf(2, "ra: %d\n", bench->ra);
	ft_printf(2, "rb: %d\n", bench->rb);
	ft_printf(2, "rr: %d\n", bench->rr);
	ft_printf(2, "rra: %d\n", bench->rra);
	ft_printf(2, "rrb: %d\n", bench->rrb);
	ft_printf(2, "rrr: %d\n", bench->rrr);
}
