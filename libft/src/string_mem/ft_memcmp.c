/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:34:44 by bmugnol-          #+#    #+#             */
/*   Updated: 2021/10/11 18:02:54 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	size_t			i;
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	cast_s1 = (unsigned char *)(s1);
	cast_s2 = (unsigned char *)(s2);
	if (size == 0)
		return (0);
	i = 0;
	while (i < size - 1 && *(cast_s1 + i) == *(cast_s2 + i))
		i++;
	return (*(cast_s1 + i) - *(cast_s2 + i));
}
