/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 12:31:18 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/09/23 10:25:07 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;

	result = malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s, ft_strlen(s) + 1);
	return (result);
}
