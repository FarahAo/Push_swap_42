/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:47:00 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/10/17 12:54:21 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (!a || !a->head || !a->head->next)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (!b || !b->head || !b->head->next)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
