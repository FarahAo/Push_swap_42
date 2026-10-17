/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:59:32 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/09/26 13:30:13 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*res;
	size_t	total;

	if (size != 0 && n > (size_t) -1 / size)
		return (NULL);
	total = n * size;
	res = malloc(total);
	if (!res)
		return (NULL);
	ft_bzero(res, total);
	return (res);
}
