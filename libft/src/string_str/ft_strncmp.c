/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:23:16 by bmugnol-          #+#    #+#             */
/*   Updated: 2021/11/22 16:56:28 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t			i;
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	cast_s1 = (unsigned char *)(s1);
	cast_s2 = (unsigned char *)(s2);
	if (size == 0)
		return (0);
	i = 0;
	while (i < size - 1 && *(cast_s1 + i) == *(cast_s2 + i) && *(cast_s1 + i))
		i++;
	return (*(cast_s1 + i) - *(cast_s2 + i));
}
