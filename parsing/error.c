/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 09:46:08 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/10/29 10:18:09 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_error(t_options *options)
{
	if (options)
	{
		free_stack(options->a);
		free_stack(options->b);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
