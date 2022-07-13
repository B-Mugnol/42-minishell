/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:55:10 by bmugnol-          #+#    #+#             */
/*   Updated: 2021/10/11 18:43:26 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s2 == 0)
		return ((char *)(s1));
	if (size < len_s2 || len_s1 == 0)
		return (NULL);
	i = 0;
	while (i < size - len_s2 + 1 && *(s1 + i + len_s2 - 1) != '\0')
	{
		if (ft_strncmp(s1 + i, s2, len_s2) == 0)
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
