#include "push_swap.h"

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
int	get_chunk_size(int size)
{
	int	chunk_size;

	chunk_size = 1;
	while ((long)chunk_size * chunk_size < size)
		chunk_size++;
	return (chunk_size);
}

#include "push_swap.h"
#include <stdio.h>

int main(void)
{
    t_stack a;
    t_node  *current;

    a = (t_stack){0};
    add_node(&a, new_node(40));
    add_node(&a, new_node(10));
    add_node(&a, new_node(50));
    add_node(&a, new_node(20));
    add_node(&a, new_node(30));
    assign_indexes(a.head);
    current = a.head;
    while (current)
    {
        printf("Value: %d | Index: %d\n",
            current->value, current->index);
        current = current->next;
    }
    free_stack(&a);
    return (0);
}
