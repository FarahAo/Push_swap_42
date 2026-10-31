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

static void	ranking(t_options *options)
{
	t_node	*current;
	t_node	*tmp;
	int		index;

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
	if (size == 2)
	{
		sa(options);
		return ;
	}
	max_bits = get_max_bits(size - 1);
	shift = 0;
	while (max_bits)
	{
		i = 0;
		pass_index(size, shift, options);
		while (options->b->size > 0)
			pa(options);
		shift++;
		max_bits--;
	}
}
