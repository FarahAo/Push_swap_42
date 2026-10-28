/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:56:33 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/29 01:28:28 by fabo-ome         ###   ########.fr       */
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
/*void	print_stack(t_options *options)
{
	while (options->a)
	{
		printf("%d\n", options->a->value);
		options->a = options->a->next;
	}
}*/

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
	stack->size = 0;
}
