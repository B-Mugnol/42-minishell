/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:28:10 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/11 23:15:51 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmerge(char *s1, char *s2)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	ft_null_free((void *)(&s1));
	ft_null_free((void *)(&s2));
	return (s);
}
