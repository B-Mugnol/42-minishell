/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 03:43:57 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/09 20:19:14 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include "minishell.h"

void	varlst_delete_node(t_var *node)
{
	if (!node)
		return ;
	free(node->name);
	free(node->value);
	free(node);
}

void	varlst_delete_var(t_var **lst, char *name)
{
	t_var	*to_be_removed;
	t_var	*head;
	t_var	*acc;
	t_var	*previous;

	if (!lst || !*lst)
		return ;
	to_be_removed = varlst_find_var(name, *lst);
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
			varlst_delete_node(*lst);
			break ;
		}
		previous = *lst;
		*lst = (*lst)->next;
	}
	*lst = head;
}

void	varlst_clear(t_var **lst)
{
	t_var	*acc;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		acc = (*lst)->next;
		varlst_delete_node(*lst);
		*lst = acc;
	}
	*lst = NULL;
}

void	delete_parse(void *parsed_node)
{
	if (!parsed_node)
		return ;
	free(((t_parse *)(parsed_node))->str);
	free(parsed_node);
}
