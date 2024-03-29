/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_lst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 03:43:57 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/09/21 21:37:55 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "var_lst.h"
#include "minishell.h"

void	var_lst_delete_node(t_var *node)
{
	if (!node)
		return ;
	free(node->name);
	free(node->value);
	free(node);
}

void	var_lst_delete_var(t_var **lst, char *name)
{
	t_var	*to_be_removed;
	t_var	*head;
	t_var	*previous;

	if (!lst || !*lst)
		return ;
	to_be_removed = var_lst_find_var(name, *lst);
	head = *lst;
	if (*lst == to_be_removed)
		head = (*lst)->next;
	previous = NULL;
	while (*lst)
	{
		if (*lst == to_be_removed)
		{
			if (previous)
				previous->next = (*lst)->next;
			var_lst_delete_node(*lst);
			break ;
		}
		previous = *lst;
		*lst = (*lst)->next;
	}
	*lst = head;
}

void	var_lst_clear(t_var **lst)
{
	t_var	*acc;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		acc = (*lst)->next;
		var_lst_delete_node(*lst);
		*lst = acc;
	}
	*lst = NULL;
}
