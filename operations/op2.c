/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuqa134 <tuqa134@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:47:00 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/10/23 17:11:38 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_options *option)
{
	if (!option || !option->a->head || !option->a->head->next)
		return ;
	rotate(&option->a);
	write(1, "ra\n", 3);
	option->counter[RA]++;
}

void	rb(t_options *option)
{
	if (!option || !option->b->head || !option->b->head->next)
		return ;
	rotate(&option->b);
	write(1, "rb\n", 3);
	option->counter[RB]++;
}

void	rr(t_options *option)
{
	if (!option)
		return ;
	rotate(&option->a);
	rotate(&option->b);
	write(1, "rr\n", 3);
	option->counter[RR]++;
}
