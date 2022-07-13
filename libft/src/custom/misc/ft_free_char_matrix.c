/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:34:19 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/03/15 22:26:54 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Matrix is expected to be NULL terminated.
void	ft_free_char_matrix(char ***m)
{
	size_t	i;

	i = 0;
	while (*(*m + i) != NULL)
	{
		free(*(*m + i));
		*(*m + i) = NULL;
		i++;
	}
	free(*m);
	*m = NULL;
}
