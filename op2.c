#include "push_swap.h"

void	ra(s_stack *a)
{
	if (!a || !a->head || !a->head->next)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(s_stack *b)
{
	if (!b || !b->head || !b->head->next)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(s_stack *a, s_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
