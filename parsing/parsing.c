/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuqa134 <tkhaleel@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:29:10 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/11/13 16:07:03 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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

static void	parse_flags(char *res, t_options *options)
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
		print_error(options);
}

static void	process_args(char **res, t_options *options)
{
	int	j;

	j = 0;
	while (res[j])
	{
		if (!is_valid_number(res[j]) || !add_to_stack(res[j], options))
		{
			free_split(res);
			print_error(options);
		}
		j++;
	}
}

void	parse_args(int argc, char **argv, t_options *options)
{
	char	**res;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			parse_flags(argv[i], options);
		else
		{
			res = ft_split(argv[i], ' ');
			if (!res)
				print_error(options);
			if (!res[0])
			{
				free_split(res);
				i++;
				continue ;
			}
			process_args(res, options);
			free_split(res);
		}
		i++;
	}
}
