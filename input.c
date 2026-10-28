/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuqa134 <tuqa134@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:29:10 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/28 18:48:28 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(const char *number)
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

static void	print_error(t_options *options)
{
	if (options)
	{
		free_stack(options->a);
		free_stack(options->b);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	add_to_stack(char *num, t_options *options)
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

static void	parse_flags(char **arr, char *res, t_options *options)
{
	if (strnncmp(res, "--bench") == 0)
		options->bench = 1;
	else if (strnncmp(res, "--simple") == 0)
		options->strategy = SIMPLE;
	else if (strnncmp(res, "--medium") == 0)
		options->strategy = MEDIUM;
	else if (strnncmp(res, "--complex") == 0)
		options->strategy = COMPLEX;
	else if (strnncmp(res, "--adaptive") == 0)
		options->strategy = ADAPTIVE;
	else
	{
		free_split(arr);
		print_error(options);
	}
}

void	parse_args(int argc, char **argv,t_options *options)
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
				parse_flags(res,res[j], options);
			else
				if (is_valid_number(res[j]))
					add_to_stack(res[j], options);
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

int	main(int argc, char **argv)
{
	t_options	*options;

	options = &(t_options){0};
	options->a = malloc(sizeof(t_stack));
	options->b = malloc(sizeof(t_stack));
	
	options->strategy = ADAPTIVE;
	if (argc > 1)
	{
		parse_args(argc, argv, options);
		//free_stack(&option.b)
		if (!compute_disorder(options->a))
			return (0);
		startegy_selector(options);
	}
	free_stack(options->a);
	return (0);
} 
