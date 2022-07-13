/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:03:17 by bmugnol-          #+#    #+#             */
/*   Updated: 2021/10/01 16:13:32 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*last_new;

	if (!new)
		return ;
	if (!lst)
		*lst = new;
	else
	{
		last_new = ft_lstlast(new);
		(*last_new).next = *lst;
		*lst = new;
	}
}
