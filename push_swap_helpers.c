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

s_list	*ft_lstnew(int value)
{
	s_list	*node;

	node = malloc(sizeof(s_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(s_list **lst, s_list *new)
{
	if (!lst ||!new)
		return ;
	new->next = *lst;
	*lst = new;
}

void print_stack(s_list *node) // this is for testing while we are currently writing the code but iam pretty sure we will eventually keep it
{
	while(node)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
}
