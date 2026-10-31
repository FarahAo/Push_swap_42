/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:04:39 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/10/29 11:04:43 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_op_counts(t_options *option)
{
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		option->counter[SA], option->counter[SB], option->counter[SS],
		option->counter[PA], option->counter[PB]);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		option->counter[RA], option->counter[RB], option->counter[RR],
		option->counter[RRA], option->counter[RRB], option->counter[RRR]);
}

static void	print_strategy(t_options *option)
{
	ft_printf(2, "[bench] strategy: ");
	if (option->strategy == SIMPLE)
		ft_printf(2, "Simple /  O(n²)\n");
	else if (option->strategy == MEDIUM)
		ft_printf(2, "Medium / O(n√n)\n");
	else if (option->strategy == COMPLEX)
		ft_printf(2, "Complex / O(n log n)\n");
	else if (option->disorder < 0.2)
		ft_printf(2, "Adaptive /  O(n²)\n");
	else if (option->disorder < 0.5)
		ft_printf(2, "Adaptive / O(n√n))\n");
	else
		ft_printf(2, "Adaptive / O(n log n)\n");
}

static void	print_disorder(t_options *option)
{
	int	percentage;

	percentage = (int)(option->disorder * 10000 + 0.5);
	ft_printf(2, "[bench] disorder: %d.", percentage / 100);
	if (percentage % 100 < 10)
		ft_printf(2, "0");
	ft_printf(2, "%d%%\n", percentage % 100);
}

void	print_bench(t_options *option)
{
	int	i;
	int	total;

	if (!option || !option->bench)
		return ;
	print_disorder(option);
	print_strategy(option);
	i = 0;
	total = 0;
	while (i < TOTAL)
		total += option->counter[i++];
	ft_printf(2, "[bench] total_ops: %d\n", total);
	print_op_counts(option);
}
