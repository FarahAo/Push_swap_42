/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_selector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:53:04 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/31 18:36:35 by fabo-ome         ###   ########.fr       */
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
	(options->disorder < 0.5)
		chunk_sort(options);
	else if (options->disorder >= 0.5)
		radix_sort(options);
}

void	startegy_selector(t_options *options)
{
	options->disorder = compute_disorder(options->a);
	if (options->disorder == 0.0)
		return ;
	if (options->strategy == SIMPLE)
		selection_sort(options);
	else if (options->startegy == MEDIUM)
		chunk_sort(options);
	else if (options->startegy == COMPLEX)
		radix_sort(options);
	else if (options->strategy == ADAPTIVE)
		adaptive(options);
}
