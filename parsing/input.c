/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:29:10 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/17 16:05:43 by tkhaleel         ###   ########.fr       */
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
		{
			*value = 1;
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
void print_error(t_options *options)
{
	if (options)
	{
		free_stack(&options.a);
		free_stack(&options.b);
	}
	write(1, 'Error\n', 6);
	exit(EXIT_FAILURE);
}
void add_to_stack(t_stack *a, char *num, t_options *options)
{
	t_node *newnode;
	int number;

	number = parse_atoi(num);
	if (is_duplicate(a.head ,num))
		printf_error(options);
	newnode = new_node(&number);
	if (!newnode)
	{
		free(split);
		printf_error(options);
	}
	add_node(*a, &number);
	}
}


void	parse_args(int argc, char **argv,t_stack *a,t_options *options)
{
	char			**res;
	int				i;
	int				j;
	int				c;

	i = 1;
	while (i < argc)
	{
		res = ft_split(argv[i], ' ');
		if (!res)
			return ;
		j = 0;
	//loop just for test
		while (res[j])
		{
			if (res[j][0] == '-' && res[j][1] == '-')
				parse_flags(res[j],*options);
			else //number validity
				if(is_valid_number(res[j]))
					add_to_stack(*a,res[j]);
				else
				{
					printf_error();
					return;
				}

			/*
			printf("%s\n", res[j]); //validate numbers and add them to the stack
			if (is_valid_number(res[j]))
				printf("Valid\n");
			else
				printf("Not Valid\n");*/
			j++;
		}
//free_split(numbers);
		i++;
	}
}

int	main(int argc, char **argv)
{

	t_stack		a;
	t_stack		b;
	t_options options;
       	options.strategy = ADAPTIVE;
	options.bench = 0;
	a.head=NULL;
	b.head = NULL;
	if (argc > 1)
	{
		parse_args(argc, argv,&a,&(options));
	}
	return (0);
}
