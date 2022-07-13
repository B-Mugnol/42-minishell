/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 23:06:29 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/13 23:15:18 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *s)
{
	long long	num;
	long long	sign;

	num = 0;
	sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == 45)
		sign = -1;
	if (*s == 43 || *s == 45)
		s++;
	while (*s >= 48 && *s <= 57)
	{
		num = 10 * num + *s - 48;
		s++;
	}
	return (num * sign);
}
