/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:02:35 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/14 22:02:51 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnchr(char *str, char c)
{
	size_t	inx;

	inx = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (inx);
		str++;
		inx++;
	}
	return (0);
}
