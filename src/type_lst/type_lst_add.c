/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_lst_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:05:24 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/05 19:42:22 by llopes-n         ###   ########.fr       */
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

int	type_lst_size(t_type *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
