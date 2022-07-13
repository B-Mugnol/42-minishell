/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:28:47 by bmugnol-          #+#    #+#             */
/*   Updated: 2021/10/11 18:35:21 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	if (!s)
		return (NULL);
	dest = malloc((ft_strlen(s) + 1) * sizeof (char));
	if (!dest)
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(dest + i) = f(i, *(s + i));
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
