/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:02:33 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/03/14 17:39:02 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Matrix is expected to be NULL terminated.
void	ft_free_matrix(void ***p, size_t line_count)
{
	size_t	i;

	i = 0;
	while (i < line_count && *(*p + i) != NULL)
	{
		free(*(*p + i));
		*(*p + i) = NULL;
		i++;
	}
	free(*p);
	*p = NULL;
}
