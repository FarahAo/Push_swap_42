#include "push_swap.h"
#include <stdio.h>
void    assign_indexes(t_node *head)
{
    t_node  *current;
    t_node  *compare;

    current = head;
    while (current)
    {
        current->index = 0;
        compare = head;
        while (compare)
        {
            if (compare->value < current->value)
                current->index++;
            compare = compare->next;
        }
        current = current->next;
    }
}
static int	get_chunk_size(int size)
{
	int	chunk_size;

	chunk_size = 1;
	while ((long)chunk_size * chunk_size < size)
		chunk_size++;
	return (chunk_size);
}

static int	find_max_position(t_node *head)
{
	int	max_index;
	int	position;
	int	best_pos;

	if (!head)
		return (-1);
	max_index = head->index;
	position = 0;
	best_pos = 0;
	while (head)
	{
		if (head->index > max_index)
		{
			max_index = head->index;
			best_pos = position;
		}
		head = head->next;
		position++;
	}
	return (best_pos);
}


static void	pull_back(t_options *options)
{
	int	pos;
	int	size;

	while (options->b->size > 0)
	{
		size = options->b->size;
		pos = find_max_position(options->b->head);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rb(options);
		}
		else
		{
			pos = size - pos;
			while (pos-- > 0)
				rrb(options);
		}
		pa(options);
	}
}

static void	push_chunks(t_options *options, int chunk)
{
	int	pushed;

	pushed = 0;
	while (options->a->size > 0)
	{
		if (options->a->head->index <= pushed)
		{
			pb(options);
			if (options->b->size > 1)
				rb(options);
			pushed++;
		}
		else if (options->a->head->index <= pushed + chunk)
		{
			pb(options);
			pushed++;
		}
		else
			ra(options);
	}
}

void	chunk_sort(t_options *options)
{
	int	chunk;

	if (!options || !options->a || !options->b)
		return ;
	if (options->a->size < 2)
		return ;
	assign_indexes(options->a->head);
	chunk = get_chunk_size(options->a->size);
	push_chunks(options, chunk);
	pull_back(options);
}
