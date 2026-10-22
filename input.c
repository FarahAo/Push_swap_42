/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:29:10 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/22 16:00:07 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *number)
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

void	print_error(t_options *options)
{
	if (options)
	{
		free_stack(&options->a);
		free_stack(&options->b);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	add_to_stack(t_stack *a, char *num, t_options *options)
{
	t_node	*newnode;
	int		number;

	if (parse_atoi(num, &number))
	{
		if (is_duplicate(a->head, number))
			print_error(options);
	}
	else
		print_error(options);
	newnode = new_node(number);
	if (!newnode)
	{
		print_error(options);
	}
	add_node(a, newnode);
}

void	parse_flags(char *res, t_options *options)
{
	if (strnncmp(res, "--bench") == 0)
		options->bench = 1;
	else if (strnncmp(res, "--simple") == 0)
		options->strategy = SIMPLE;
	else if (strnncmp(res, "--medium") == 0)
		options->strategy = MEDIUM;
	else if (strnncmp(res, "--complex") == 0)
		options->strategy = COMPLEX;
	else
		print_error(options);
}

void	parse_args(int argc, char **argv, t_stack *a, t_options *options)
{
	char			**res;
	int				i;
	int				j;

	i = 1;
	while (i < argc)
	{
		res = ft_split(argv[i], ' ');
		if (!res)
			print_error(options);
		j = 0;
		while (res[j])
		{
			if (res[j][0] == '-' && res[j][1] == '-')
				parse_flags(res[j], options);
			else
				if (is_valid_number(res[j]))
					add_to_stack(a, res[j], options);
				else
				{
					free_split(res);
					print_error(options);
				}
			j++;
		}
		free_split(res);
		i++;
	}
}

/*int	main(int argc, char **argv)
{
	t_options	options;

	options.bench = 0;
	options.a.head = NULL;
	options.b.head = NULL;
	options.strategy = ADAPTIVE;
	if (argc > 1)
	{
		parse_args(argc, argv, &options.a, &(options));
		//free_stack(&option.b)
	}
	free_stack(&options.a);
	return (0);
} */
