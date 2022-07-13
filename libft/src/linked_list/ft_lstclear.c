/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 17:31:44 by bmugnol-          #+#    #+#             */
/*   Updated: 2021/10/08 12:24:22 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*acc;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		acc = ((**lst).next);
		ft_lstdelone(*lst, del);
		*lst = acc;
	}
	*lst = NULL;
}
