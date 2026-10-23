/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:56:17 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/10/23 18:10:14 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void  adaptive(t_options *options)
{
	if (!options)
		return ;	
	options->disorder = compute_disorder(&options->a);

	if (options->disorder == 0.0)
		return;
	if (options->disorder < 0.2)
		simple_sort(options);
	else if (options->disorder < 0.5)
		medium_sort(options);
	else if(options->disorder >= 0.5)
		complex_sort(options);
}
