/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:34:44 by bmugnol-          #+#    #+#             */
/*   Updated: 2021/10/02 23:42:47 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*result;
	t_list	*temp;
	t_list	*new_lst;

	new_lst = NULL;
	while (lst)
	{
		result = f((*lst).content);
		if (!result)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		temp = ft_lstnew(result);
		if (!temp)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, temp);
		lst = (*lst).next;
	}
	return (new_lst);
}
