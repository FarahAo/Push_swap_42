/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuqa134 <tuqa134@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:20:39 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/23 17:11:28 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_options *option)
{
	if (!option || !option->a->head || !option->a->head->next)
		return ;
	swap(&option->a);
	write(1, "sa\n", 3);
	option->counter[SA]++;
}

void	sb(t_options *option)
{
	if (!option || !option->b->head || !option->b->head->next)
		return ;
	swap(&option->b);
	write(1, "sb\n", 3);
	option->counter[SB]++;
}

void	ss(t_options *option)
{
	if (!option)
		return ;
	if (option->a->head && option->a->head->next)
		swap(&option->a);
	if (option->b->head && option->b->head->next)
		swap(&option->b);
	write(1, "ss\n", 3);
	option->counter[SS]++;
}

void	pa(t_options *option)
{
	t_node	*tmp;
	t_stack	*a;
	t_stack	*b;

	if (!option)
		return ;
	a = &option->a;
	b = &option->b;
	if (!b->head)
		return ;
	tmp = b->head;
	b->head = b->head->next;
	tmp->next = a->head;
	a->head = tmp;
	a->size++;
	b->size--;
	write(1, "pa\n", 3);
	option->counter[PA]++;
}

void	pb(t_options *option)
{
	t_node	*tmp;
	t_stack	*a;
	t_stack	*b;

	if (!option)
		return ;
	a = &option->a;
	b = &option->b;
	if (!a->head)
		return ;
	tmp = a->head;
	a->head = a->head->next;
	tmp->next = b->head;
	b->head = tmp;
	a->size--;
	b->size++;
	write(1, "pb\n", 3);
	option->counter[PB]++;
}
