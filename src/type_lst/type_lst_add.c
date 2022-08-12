/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_lst_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:05:24 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/12 20:09:14 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_lst.h"

t_type	*type_lst_new(char *str_in, t_token type)
{
	t_type	*node;

	node = malloc(sizeof(t_type));
	node->str = str_in;
	node->type = type;
	node->next = NULL;
	return (node);
}

void	type_lst_add_back(t_type **lst, t_type *new)
{
	t_type	*head;

	if (!*lst)
		*lst = new;
	else
	{
		head = *lst;
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new;
		*lst = head;
	}
}

void	type_lst_add_front(t_type **lst, t_type *new)
{
	if (!*lst)
		*lst = new;
	new->next = *lst;
	*lst = new;
}
