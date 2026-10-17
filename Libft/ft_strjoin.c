/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 17:06:13 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/09/18 15:35:44 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	j;
	size_t	i;

	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	j = 0;
	while (s1[j])
	{
		res[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		res[j + i] = s2[i];
		i++;
	}
	res[j + i] = '\0';
	return (res);
}
