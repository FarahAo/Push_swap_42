/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 14:18:57 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/09/23 10:20:18 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_sep(char c, char sep)
{
	return (c == sep);
}

static int	word_count(char const *s, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], sep))
			i++;
		if (s[i])
			count++;
		while (s[i] && !is_sep(s[i], sep))
			i++;
	}
	return (count);
}

static void	free_split(char **res, int word)
{
	while (word > 0)
	{
		word--;
		free(res[word]);
	}
	free(res);
}

static char	**split_copy(char const *s, char **res, char c)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], c))
			i++;
		if (!s[i])
			break ;
		j = 0;
		while (s[i + j] && !is_sep(s[i + j], c))
			j++;
		res[word] = malloc(j + 1);
		if (!res[word])
			return (free_split(res, word), NULL);
		j = 0;
		while (s[i] && !is_sep(s[i], c))
			res[word][j++] = s[i++];
		res[word++][j] = '\0';
	}
	res[word] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!res)
		return (NULL);
	return (split_copy(s, res, c));
}
