/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_selector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:53:04 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/29 10:22:51 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	adaptive(t_options *options)
{
	if (!options)
		return ;
	if (options->disorder == 0.0)
		return ;
	if (options->disorder < 0.2)
		selection_sort(options);
	/*else if (options->disorder < 0.5)
		medium_sort(options->a, options->b);
	else if (options->disorder >= 0.5)
		complex_sort(options->a, options->b);*/
}

void	startegy_selector(t_options *options)
{
	options->disorder = compute_disorder(options->a);
	if (options->disorder == 0.0)
		return ;
	if (options->strategy == SIMPLE)
		selection_sort(options);
	/*	else if (options->startegy == MEDIUM)
		else if (options->startegy == COMPLEX) */
	else if (options->strategy == ADAPTIVE)
		adaptive(options);
}
