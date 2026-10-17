/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:29:10 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/17 10:55:38 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

#include "libft.h"

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

int	ft_atoi(const char *str, int *value)
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
		{
			*value = 1
				return (0);
		}
		i++;
	}
	return ((int)(num * sign));
}

int	is_valid_number(char *number)
{
	int	i;

	if (!number || !number[0])
		return (0);
	i = 0;
	if (number[i] == '+' || number[i] == '-')
		i++;
	if (!number[i])
		return (0);
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

void	parse_args(int argc, char **argv)
{
	char			**numbers;
	int				i;
	int				j;

	i = 1;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			return ;
		j = 0;
	//loop just for test
		while (numbers[j])
		{
			printf("%s\n", numbers[j]); //validate numbers and add them to the stack
			if (is_valid_number(numbers[j]))
				printf("Valid\n");
			else
				printf("Not Valid\n");
			j++;
		}
//free_split(numbers);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		parse_args(argc, argv);
	return (0);
}
