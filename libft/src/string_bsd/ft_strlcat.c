/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:54:05 by bmugnol-          #+#    #+#             */
/*   Updated: 2021/09/23 21:42:28 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*(dest + i) != '\0' && i < size)
		i++;
	if (i == size)
		return (ft_strlen(src) + size);
	while (i < size - 1 && *src != '\0')
	{
		*(dest + i) = *src;
		src++;
		i++;
	}
	*(dest + i) = '\0';
	if (*src != '\0')
		return (ft_strlen(src) + size - 1);
	return (i);
}
