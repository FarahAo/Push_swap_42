/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 10:57:41 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/31 18:31:56 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_max_bits(int biggest_index)
{
	int	max_bits;

	max_bits = 0;
	while (biggest_index)
	{
		biggest_index /= 2;
		max_bits++;
	}
	return (max_bits);
}

static void	pass_index(int size, int shift, t_options *options)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((options->a->head->index >> shift) & 1) == 0)
			pb(options);
		else
			ra(options);
		i++;
	}
}

void	radix_sort(t_options *options)
{
	int	size;
	int	max_bits;
	int	shift;

	size = options->a->size;
	if (size < 2)
		return ;
	assign_indexes(options->a->head);
	if (size == 2)
	{
		sa(options);
		return ;
	}
	max_bits = get_max_bits(size - 1);
	shift = 0;
	while (max_bits)
	{
		pass_index(size, shift, options);
		while (options->b->size > 0)
			pa(options);
		shift++;
		max_bits--;
	}
}
