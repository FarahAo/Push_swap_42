/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:47:20 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/09/29 17:50:09 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_unbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += print_unbr(n / 10);
	count += print_char((n % 10) + '0');
	return (count);
}
