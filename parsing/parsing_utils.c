/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:56:29 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/29 02:14:43 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **res)
{
	size_t	i;

	i = 0;
	if (!res)
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

int	strnncmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}

int	parse_atoi(const char *str, int *value)
{
	long		num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i])
	{
		num = (num * 10) + (str[i] - '0');
		if ((sign == 1 && num > 2147483647L)
			|| (sign == -1 && num > 2147483648L))
			return (0);
		i++;
	}
	*value = (int)(num * sign);
	return (1);
}

void	add_to_stack(char *num, t_options *options)
{
	t_node	*newnode;
	int		number;

	if (parse_atoi(num, &number))
	{
		if (is_duplicate(options->a->head, number))
			print_error(options);
	}
	else
		print_error(options);
	newnode = new_node(number);
	if (!newnode)
		print_error(options);
	add_node(options->a, newnode);
}
