/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:17:21 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/10/29 10:21:24 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_options	options;
	t_stack		a;
	t_stack		b;

	options = (t_options){0};
	a = (t_stack){0};
	b = (t_stack){0};
	options.a = &a;
	options.b = &b;
	options.strategy = ADAPTIVE;
	if (argc > 1)
	{
		parse_args(argc, argv, &options);
		startegy_selector(&options);
		print_bench(&options);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
