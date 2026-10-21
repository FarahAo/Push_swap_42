/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:56:33 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/17 11:13:24 by fabo-ome         ###   ########.fr       */
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
	node->next = NULL;
	return (node);
}

void	add_node(t_stack *lst, t_node *new)
{
	if (!lst || !new)
		return ;
	new->next = lst->head;
	lst->head = new;
}

void	print_stack(t_node *a)
// this is for testing while we are currently writing the code but iam pretty sure we will eventually keep it
{
	
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*nextn;

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
}
