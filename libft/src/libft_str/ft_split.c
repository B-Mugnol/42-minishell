/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:24:20 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/01/28 23:03:31 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	word_count;
	size_t	i;

	if (!*s)
		return (0);
	i = 0;
	word_count = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != c && (*(s + i + 1) == c || *(s + i + 1) == '\0'))
			word_count++;
		i++;
	}
	return (word_count);
}

static size_t	count_not_char(char const *s, char c)
{
	size_t	i;

	if (!*s)
		return (0);
	i = 0;
	while (*(s + i) != '\0' && *(s + i) != c)
		i++;
	return (i);
}

static void	free_matrix(void **m, size_t line_count)
{
	size_t	i;

	if (line_count == 0)
		return ;
	i = 0;
	while (i < line_count)
	{
		free(m[i]);
		i++;
	}
	free(m);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	dest = malloc((count_words(s, c) + 1) * sizeof (char *));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s + i) != '\0')
	{
		while (*(s + i) == c && *(s + i) != '\0')
			i++;
		if (*(s + i) == '\0')
			break ;
		dest[j] = ft_substr(s, i, count_not_char(s + i, c));
		if (!dest[j])
			free_matrix((void *)(dest), j);
		i += count_not_char(s + i, c);
		j++;
	}
	dest[j] = NULL;
	return (dest);
}
