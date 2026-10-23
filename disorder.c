/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 17:07:50 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/23 15:14:26 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	calculate_disorder(t_node *current, long size)
{
	t_node	*temp;
	long	i;
	long	j;
	long	mistakes;
	long	total_pairs;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < size)
	{
		j = i + 1;
		temp = current->next;
		while (j < size)
		{
			if (current->value > temp->value)
				mistakes += 1;
			total_pairs += 1;
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

	if (!a || a->size <= 1)
		return (0.0);
	current = a->head;
	return (calculate_disorder(current, a->size));
}
