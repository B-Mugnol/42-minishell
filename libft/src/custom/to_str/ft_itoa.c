/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:39:53 by bmugnol-          #+#    #+#             */
/*   Updated: 2021/10/11 17:53:41 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	digit_count;

	if (n == 0)
		return (1);
	digit_count = 0;
	while (n != 0)
	{
		n /= 10;
		digit_count++;
	}
	return (digit_count);
}

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		is_negative;
	int		digit_count;

	is_negative = 0;
	digit_count = count_digits(n);
	if (n < 0)
		is_negative = 1;
	s = malloc((digit_count + is_negative + 1) * sizeof (char));
	if (!s)
		return (NULL);
	if (is_negative)
		s[0] = '-';
	*(s + digit_count + is_negative) = '\0';
	while (digit_count > 0)
	{
		*(s + digit_count - 1 + is_negative) = ft_abs(n % 10) + '0';
		n /= 10;
		digit_count--;
	}
	return (s);
}
