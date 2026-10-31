/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:46:24 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/10/23 16:12:33 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_nbr(int fd, int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += print_char(fd, '-');
		nb = -nb;
	}
	if (nb > 9)
		count += print_nbr(fd, nb / 10);
	count += print_char(fd, (nb % 10) + '0');
	return (count);
}
