/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:17:21 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/10/29 18:24:04 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_options	options;
	t_stack		a;
	t_stack		b;

	if (argc == 1)
		return (0);
	options = (t_options){0};
	a = (t_stack){0};
	b = (t_stack){0};
	options.a = &a;
	options.b = &b;
	options.strategy = ADAPTIVE;
	parse_args(argc, argv, &options);
	if (a.size == 0)
		print_error(&options);
	startegy_selector(&options);
	print_bench(&options);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

