/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:58:37 by bmugnol-          #+#    #+#             */
/*   Updated: 2021/09/26 13:55:03 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	cast_c;

	i = 0;
	p = (unsigned char *)(s);
	cast_c = (unsigned char)(c);
	while (i < size)
	{
		if (*(p + i) == cast_c)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
