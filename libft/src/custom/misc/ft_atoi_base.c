/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:57:48 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/28 18:05:46 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid_base(char *base, int length);
static int	find_char_index(char *str, char to_find);

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sign;
	int	num;
	int	index;

	base_len = ft_strlen(base);
	if (!is_valid_base(base, base_len))
		return (0);
	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (*str != '\0')
	{
		index = find_char_index(base, *str++);
		if (index == -1)
			break ;
		num = num * base_len + index;
	}
	return (num * sign);
}

static int	is_valid_base(char *base, int length)
{
	if (length <= 1)
		return (0);
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-')
			return (0);
		if (*base < 33 || *base > 126)
			return (0);
		if (find_char_index(base + 1, *base) >= 0)
			return (0);
		base++;
	}
	return (1);
}

static int	find_char_index(char *str, char to_find)
{
	int		i;

	i = 0;
	if (to_find == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}
