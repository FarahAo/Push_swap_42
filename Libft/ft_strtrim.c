/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 17:50:43 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/09/26 13:05:48 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	char const	*s;
	size_t		start;
	size_t		end;

	if (!s1 || ft_strlen(s1) == 0)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (in_set(s1[start], set))
		start++;
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	while (in_set(s1[end], set))
		end--;
	str = malloc(end - start + 2);
	if (!str)
		return (NULL);
	s = s1 + start;
	ft_strlcpy(str, s, end - start + 2);
	return (str);
}
