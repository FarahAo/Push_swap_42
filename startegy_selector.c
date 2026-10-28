/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startegy_selector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:53:04 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/28 18:53:06 by fabo-ome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    startegy_selector(t_options *options)
{
    if (options->strategy == SIMPLE)
        selection_sort(options);
    /*else if (options->startegy == MEDIUM)
        // 
    else if (options->startegy == COMPLEX)
        //
    else if (options->startegy == ADAPTIVE)
        adaptive(options);
*/
}
