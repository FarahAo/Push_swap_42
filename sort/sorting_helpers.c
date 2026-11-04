/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:06:58 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/11/04 19:04:21 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	sort_three(t_options *options)
{
	int	top;
	int	mid;
	int	last;

	if (!options || !options->a ||!options->a->head)
		return ;
	top = options->a->head->value;
	mid = options->a->head->next->value;
	last = options->a->head->next->next->value;
	if (top < mid && mid > last && top < last) //1 3 2 
	{
		sa(options);
		ra(options);
	}
	else if (top > mid && mid < last && top < last) //2 1 3 
		sa(options);
	else if (top < mid && top < last && mid > last) // 2 3 1
		rra(options);
	else if (top > mid && top > last && mid < last) // 3 1 2
		ra(options);
	else if (top > mid && mid > last) // 3 2 1
	{
		sa(options);
		rra(options);
	}
}

void	sort_five(t_options *options)
{
	t_node	*current;
	int		min_position;

	if (!options ||!options->a ||!options->b->size)
		return ;
	while (options->a->size > 3)
	{
		current = options->a->head;
		min_position = find_min(current);
		bring_to_top(min_position, options);
		pb(options);
	}
	sort_three(options);
	while (options->b->size > 0)
		pa(options);
}
