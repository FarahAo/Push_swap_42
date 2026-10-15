/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:56:33 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/13 16:31:38 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_node	*ft_lstnew(int value)
{
	s_node	*node;

	node = malloc(sizeof(s_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(s_stack *lst, s_node *new)
{
	if (!lst ||!new)
		return ;
	new->next = lst->head;
	lst->head = new;
}

void print_stack(s_node *node) // this is for testing while we are currently writing the code but iam pretty sure we will eventually keep it
{
	while(node)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
}

void	swap(s_stack *p)
{	
	s_node *tmp;
	if (!p || !p->head || !p->head->next)
		return ;
	tmp = p->head;
	p ->head = p->head->next;
	tmp->next = p->head->next;
	p->head->next = tmp;
}

void	rotate(s_stack *p)
{
	s_node *tmp;
	s_node *last;

	if (!p || !p->head || !p->head->next)
		return ;
	tmp = p->head;
	last = tmp;
	p->head = p->head->next;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}
