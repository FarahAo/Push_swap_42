/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:57:08 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/28 18:41:55 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_node *current)
{
	int	min_value;
	int	position;
	int	min_position;

	min_position = 0;
	min_value = current->value;
	position = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_position = position;
		}
		position++;
		current = current->next;
	}
	return (min_position);
}

static void	bring_to_top(int min_position, t_options *options)
{
	int	size;
	int	res;
	int	i;

	size = options->a->size;
	res = size - min_position;
	i = 0;
	if (res < min_position)
	{
		while (i < res)
		{
			rra(options);
			i++;
		}
	}
	else
	{	
		while (i < min_position)
		{
			ra(options);
			i++;
		}
	}
}
void	selection_sort(t_options *options)
{
	if (options->a->size ==  2)
	{
		sa(options);
		return ;
	}
	while (options->a->size)
	{
		t_node *current;
		int	min_position;
	
		current = options->a->head;
		min_position = find_min(current);
		bring_to_top(min_position, options);
		pb(options);
	}
    while (options->b->size > 0)
	    pa(options);
}
