/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xto_uppercase_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:44:50 by bmugnol-          #+#    #+#             */
/*   Updated: 2021/11/22 17:45:25 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned int n);

char	*ft_xto_uppercase_a(unsigned int n)
{
	char	*s;
	int		digit_count;

	digit_count = count_digits(n);
	s = malloc(sizeof(char) * (digit_count + 1));
	if (!s)
		return (NULL);
	*(s + digit_count) = '\0';
	while (digit_count > 0)
	{
		if (n % 16 < 10)
			*(s + digit_count - 1) = n % 16 + '0';
		else
			*(s + digit_count - 1) = n % 16 - 10 + 'A';
		n /= 16;
		digit_count--;
	}
	return (s);
}

static int	count_digits(unsigned int n)
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
