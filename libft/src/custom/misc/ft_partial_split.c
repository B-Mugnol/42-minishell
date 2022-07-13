/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partial_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:19:43 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/03/29 22:09:59 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		count_words(char const *s, char splitter, char delimiter);
static char const	*separator(char const *s, char **dest, char splitter,
						char delimiter);

char	**ft_partial_split(char const *s, char splitter, char delimiter)
{
	char	**dest;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	dest = malloc((count_words(s, splitter, delimiter) + 1) * sizeof (char *));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0' && j < count_words(s, splitter, delimiter))
	{
		i = separator(s + i, dest + j, splitter, delimiter) - s;
		if (!dest[j])
		{
			ft_free_matrix((void *)(&dest), j);
			return (NULL);
		}
		j++;
	}
	dest[j] = NULL;
	return (dest);
}

static size_t	count_words(char const *s, char splitter, char delimiter)
{
	size_t	word_count;
	size_t	i;
	size_t	j;

	i = -1;
	word_count = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == delimiter)
		{
			word_count++;
			j = 1;
			while (s[i + j] != delimiter && s[i + j] != '\0')
				j++;
			if (i > 0 && s[i - 1] != splitter && s[i + j] != '\0')
				word_count++;
			i += j;
			if (s[i] == '\0')
				break ;
		}
		else if (s[i] != splitter && (s[i + 1] == splitter
				|| s[i + 1] == '\0'))
			word_count++;
	}
	return (word_count);
}

static char const	*separator(char const *s, char **dest, char splitter,
	char delimiter)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (s[i] == splitter && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (s + i);
	k = 0;
	if (s[i] == delimiter)
	{
		while ((s[i + k] != delimiter && s[i + k] != '\0') || k == 0)
			k++;
		if (k == 1)
			*dest = ft_substr(s, i, k);
		else if (s[i + k] == '\0')
			*dest = ft_substr(s, i + 1, k - 1);
		else
			*dest = ft_substr(s, ++i, k - 1);
		return (s + i + k);
	}
	while (s[i + k] != splitter && s[i + k] != delimiter && s[i + k] != '\0')
		k++;
	*dest = ft_substr(s, i, k);
	return (s + i + k);
}
