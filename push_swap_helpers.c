/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:56:33 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/15 13:10:17 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node	*ft_lstnew(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_stack *lst, t_node *new)
{
	if (!lst || !new)
		return ;
	new->next = lst->head;
	lst->head = new;
}

void	print_stack(t_node *node)
// this is for testing while we are currently writing the code but iam pretty sure we will eventually keep it
{
	while (node)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
}

void	swap(t_stack *p)
{
	t_node	*tmp;

	if (!p || !p->head || !p->head->next)
		return ;
	tmp = p->head;
	p->head = p->head->next;
	tmp->next = p->head->next;
	p->head->next = tmp;
}

void	rotate(t_stack *p)
{
	t_node	*tmp;
	t_node	*last;

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

void	reverse_rotate(t_stack *p)
{
	t_node	*tmp;
	t_node	*last;

	if (!p || !p->head || !p->head->next)
		return ;
	tmp = p->head;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = p->head;
	p->head = last;
}
