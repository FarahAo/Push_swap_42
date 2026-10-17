/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 18:59:34 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/09/20 18:04:50 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	num_len(long n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*itoa_copy(long nb, char *res, size_t size)
{
	res[size] = '\0';
	if (nb == 0)
	{
		res[0] = '0';
		return (res);
	}
	size--;
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		res[size] = (nb % 10) + '0';
		nb /= 10;
		if (size > 0)
			size--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	size;
	char	*res;

	nb = n;
	size = num_len(nb);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	res = itoa_copy(nb, res, size);
	return (res);
}
