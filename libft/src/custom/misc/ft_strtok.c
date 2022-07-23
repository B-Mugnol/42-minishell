/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:56:34 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/22 22:48:25 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *buffer, const char *delimiter)
{
	static char	*str;
	size_t		inx;

	if (buffer)
		str = buffer;
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
