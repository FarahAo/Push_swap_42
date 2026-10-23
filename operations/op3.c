/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuqa134 <tuqa134@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:47:00 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/10/23 17:11:48 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_options *option)
{
	if (!option || !option->a.head || !option->a.head->next)
		return ;
	reverse_rotate(&option->a);
	write(1, "rra\n", 4);
	option->counter[RRA]++;
}

void	rrb(t_options *option)
{
	if (!option || !option->b.head || !option->b.head->next)
		return ;
	reverse_rotate(&option->b);
	write(1, "rrb\n", 4);
	option->counter[RRB]++;
}

void	rrr(t_options *option)
{
	if (!option)
		return ;
	if (option->a.head && option->a.head->next)
		reverse_rotate(&option->a);
	if (option->b.head && option->b.head->next)
		reverse_rotate(&option->b);
	write(1, "rrr\n", 4);
	option->counter[RRR]++;
}
