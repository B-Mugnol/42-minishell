/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:42:56 by bmugnol-          #+#    #+#             */
/*   Updated: 2021/11/25 22:47:06 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned long int n);

char	*ft_ptoa(void *p)
{
	unsigned long int	n;
	char				*s;
	int					digit_count;

	n = (unsigned long int)(p);
	if (!n)
		return (NULL);
	digit_count = count_digits(n);
	s = malloc(sizeof(char) * (digit_count + 3));
	if (!s)
		return (NULL);
	*s = '0';
	*(s + 1) = 'x';
	*(s + digit_count + 2) = '\0';
	while (digit_count > 0)
	{
		if (n % 16 < 10)
			*(s + digit_count + 1) = n % 16 + '0';
		else
			*(s + digit_count + 1) = n % 16 - 10 + 'a';
		n /= 16;
		digit_count--;
	}
	return (s);
}

static int	count_digits(unsigned long int n)
{
	int	digit_count;

	if (n == 0)
		return (1);
	digit_count = 0;
	while (n != 0)
	{
		n /= 16;
		digit_count++;
	}
	return (digit_count);
}
