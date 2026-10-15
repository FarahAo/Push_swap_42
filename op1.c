#include "push_swap.h"

void	swap_sa(t_stack *a)
{
	if (!a || !a->head || !a->head->next)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void	swap_sb(t_stack *b)
{
	if (!b || !b->head || !b->head->next)
		return ;
	swap(b);
	write(1, "sb\n", 3);
}

void	swap_ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!b || !b->head || !a)
		return ;
	tmp = b->head;
	b->head = b->head->next;
	tmp->next = a->head;
	a->head = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!a || !a->head || !b)
		return ;
	tmp = a->head;
	a->head = a->head->next;
	tmp->next = b->head;
	b->head = tmp;
	write(1, "pb\n", 3);
}
