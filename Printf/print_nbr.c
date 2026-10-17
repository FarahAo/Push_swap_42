/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:46:24 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/09/29 17:47:01 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_nbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += print_char('-');
		nb = -nb;
	}
	if (nb > 9)
		count += print_nbr(nb / 10);
	count += print_char((nb % 10) + '0');
	return (count);
}
