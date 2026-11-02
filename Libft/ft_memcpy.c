/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 13:45:39 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/09/26 12:15:06 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*sr;
	char		*dst;
	size_t		i;

	if (!dest && !src)
		return (0);
	i = 0;
	dst = dest;
	sr = src;
	while (i < n)
	{
		dst[i] = sr[i];
		i++;
	}
	return (dest);
}
