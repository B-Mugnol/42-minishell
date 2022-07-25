/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:56:34 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/26 00:08:29 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *buffer, const char *delimiter)
{
	static char	*str;
	size_t		inx;

	if (buffer)
		str = buffer;
	inx = 0;
	while (str[inx])
	{
		if (ft_strrchr(delimiter, str[inx]))
		{
			str[inx] = '\0';
			buffer = str;
			str += inx + 1;
			return (buffer);
		}
		inx++;
	}
	return (NULL);
}
