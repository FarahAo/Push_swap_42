/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:56:33 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/29 11:06:55 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	add_node(t_stack *stack, t_node *new)
{
	t_node	*current;

	if (!stack || !new)
		return ;
	new->next = NULL;
	if (!stack->head)
		stack->head = new;
	else
	{
		current = stack->head;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	stack->size++;
}

void	free_stack(t_stack *stack)
{
	t_node  *current;
	t_node  *nextn;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		nextn = current->next;
		free(current);
		current = nextn;
	}
	stack->head = NULL;
	stack->size = 0;
}
