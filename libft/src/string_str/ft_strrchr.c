/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:26:53 by bmugnol-          #+#    #+#             */
/*   Updated: 2021/10/03 19:59:57 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	cast_c;

	cast_c = (char)(c);
	len = ft_strlen(s);
	if (cast_c == '\0')
		return ((char *)(s + len));
	while (len > 0)
	{
		if (*(s + len) == cast_c)
			return ((char *)(s + len));
		len--;
	}
	if (*s == cast_c)
		return ((char *)(s));
	return (NULL);
}
