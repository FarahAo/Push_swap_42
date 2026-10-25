#include "push_swap.h"

void selection_sort(t_options *options)
{
    while (options->a->size)
    {
        t_node *current;
        current = options->a->head;
        int min_value = current->value;
        int min_position = 0;
        int position = 0;
        while (current)  // to find min value and min position 
        {
            if (current->value < min_value)
            {
                    min_value = current->value;
                    min_position = position;
            }
            position++;
            current = current->next;
        }
        int size = options->a->size;
        int res = size - min_position;
        if (res < min_position)
   {
        int rra_count = size - min_position;
        int i = 0;
        while (i < rra_count)
        {
            rra(options);
            i++;
        }
    }
        else 
        {
            int ra_count = min_position;
            int j = 0;
            while (j < ra_count)
            {
                ra(options);
                j++;
            }
        }
        pb(options);
        }
        while (options->b->size > 0)
            pa(options);
    }