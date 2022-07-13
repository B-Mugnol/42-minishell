/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:09:11 by bmugnol-          #+#    #+#             */
/*   Updated: 2021/10/11 18:33:03 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!s3)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		*(s3 + i++) = *s1++;
	while (*s2 != '\0')
		*(s3 + i++) = *s2++;
	*(s3 + i) = '\0';
	return (s3);
}
