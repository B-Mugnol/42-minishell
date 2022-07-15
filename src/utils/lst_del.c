/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 03:43:57 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/07/15 04:41:07 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_delete_node(t_node *node)
{
	if (!node)
		return ;
	free(node->name);
	free(node->value);
	free(node);
}

void	lst_delete_var(t_node **lst, char *name)
{
	t_node	*to_be_removed;
	t_node	*head;
	t_node	*acc;
	t_node	*previous;

	if (!lst || !*lst)
		return ;
	to_be_removed = find_var(name, *lst);
	head = *lst;
	if (*lst == to_be_removed)
		head = (*lst)->next;
	while (*lst)
	{
		if (*lst == to_be_removed)
		{
			acc = (*lst)->next;
			if (previous)
				previous->next = acc;
			lst_delete_node(*lst);
			break ;
		}
		previous = *lst;
		*lst = (*lst)->next;
	}
	*lst = head;
}

void	lst_clear(t_node **lst)
{
	t_node	*acc;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		acc = (*lst)->next;
		lst_delete_node(*lst);
		*lst = acc;
	}
	*lst = NULL;
}
