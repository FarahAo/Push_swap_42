/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:57:10 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/09/26 12:26:28 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*sr;
	char		*dst;

	if (dest == src || n == 0)
		return (dest);
	sr = src;
	dst = dest;
	if (dst < sr)
	{
		while (n--)
			*dst++ = *sr++;
	}
	else
	{
		while (n--)
			dst[n] = sr[n];
	}
	return (dest);
}
