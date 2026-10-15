/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuqa134 <tuqa134@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:45:53 by tuqa134           #+#    #+#             */
/*   Updated: 2026/10/15 10:48:48 by tuqa134          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(s_stack *a)
{
	if (!a || !a->head || !a->head->next)
		return ;
	reverse_rotate(a);
	write(1, "rra\n", 4);
}
void	rrb(s_stack *b)
{
	if (!b || !b->head || !b->head->next)
		return ;
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
void	rrr(s_stack *a, s_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);

	write(1, "rrr\n", 4);
}