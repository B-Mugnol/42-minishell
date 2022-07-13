/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:03:28 by bmugnol-          #+#    #+#             */
/*   Updated: 2021/09/30 15:35:23 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n / 10 == 0)
		ft_putchar_fd(ft_abs(n % 10) + '0', fd);
	else
	{
		ft_putnbr_fd(ft_abs(n / 10), fd);
		ft_putchar_fd(ft_abs(n % 10) + '0', fd);
	}
}
