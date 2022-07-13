/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:33:44 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/07/13 02:10:03 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb >= __SIZE_MAX__ / size)
		return (NULL);
	p = malloc(nmemb * size);
	if (nmemb == 0 || size == 0)
		return (p);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
