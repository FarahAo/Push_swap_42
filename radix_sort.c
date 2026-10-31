/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 10:57:41 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/31 17:56:28 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ranking(t_options *options)
{
	t_node	*current;
	t_node	*tmp;
	int	index;

	if (!options || !options->a)
		return ;
	current = options->a->head;
	while (current)
	{
		tmp = current;
		index = 0;
		while (tmp)
		{
			if (current->value > tmp->value)
				index++;
			tmp = tmp->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	radix_sort(t_options *options)
{
	int	size;
	int	biggest_index;
	int	max_bits;
	int	i;
	int	shift;

	size = options->a->size;
	biggest_index = size - 1;
	max_bits = 0;
	i = 0;
	shift = 0;
	while (biggest_index)
	{
		biggest_index /= 2;
		max_bits++;
	}
	while (max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((options->a->head->index >> shift) & 1) == 0)
				pb(options);
			else 
				ra(options);
			i++;
		}
		while (options->b->size > 0)
			pa(options);
		shift++;
		max_bits--;
	}
}
