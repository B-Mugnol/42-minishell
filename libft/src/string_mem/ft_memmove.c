/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:53:31 by bmugnol-          #+#    #+#             */
/*   Updated: 2021/09/23 21:21:40 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*cast_src;
	char	*cast_dest;
	size_t	i;

	cast_src = (char *)(src);
	cast_dest = (char *)(dest);
	i = 0;
	if (src > dest)
	{
		while (i < size)
		{
			*(cast_dest + i) = *(cast_src + i);
			i++;
		}
	}
	else if (dest > src)
	{
		while (i < size)
		{
			*(cast_dest + size - i - 1) = *(cast_src + size - i - 1);
			i++;
		}
	}
	return (dest);
}
