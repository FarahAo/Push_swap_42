/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 17:07:50 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/22 14:10:24 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	stack_size(t_stack *a)
{
	t_node	*current;
	long	count;

	count = 0;
	if (!a)
		return (0);
	current = a->head;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

static double	calculate_disorder(t_node *current, long size, long total_pairs)
{
	t_node	*temp;
	long	i;
	long	j;
	long	mistakes;

	i = 0;
	mistakes = 0;
	while (i < size)
	{
		j = i + 1;
		temp = current->next;
		while (j < size)
		{
			if (current->value > temp->value)
				mistakes += 1;
			temp = temp->next;
			j++;
		}
		current = current->next;
		i++;
	}
	return ((double)(mistakes) / (double)(total_pairs));
}

double	compute_disorder(t_stack *a)
{
	t_node	*current;
	long	size;
	long	total_pairs;

	size = stack_size(a);
	if (!a || size <= 1)
		return (0.0);
	current = a->head;
	total_pairs = size * (size -1) / 2;
	return (calculate_disorder(current, size, total_pairs));
}
