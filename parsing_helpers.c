/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:56:29 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/21 16:56:33 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_split(char **res)
{
    size_t i;
    i = 0;
    if(!res)
        return ;
    while (res[i])
    {
        free(res[i]);
        i++;
    }
    free(res);
}

int	is_duplicate(t_node *stack, int val)
{
	while (stack)
	{
		if (stack ->value == val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int strnncmp(char *s1, char *s2)
{
	size_t i;

	i = 0;
	while(s1[i] == s2[i] && s1[i])
	  i++;
	return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}

