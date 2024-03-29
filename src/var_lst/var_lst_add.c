/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_lst_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:01:12 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/05 20:46:45 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "var_lst.h"

t_var	*var_lst_new(char *name, char *value)
{
	t_var	*node;

	node = malloc(sizeof(t_var));
	node->name = name;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	var_lst_add_back(t_var **lst, t_var *new)
{
	t_var	*head;

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

void	var_lst_add_front(t_var **lst, t_var *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void	var_lst_add_var(t_var **lst, t_var *new)
{
	t_var	*old;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	old = var_lst_find_var(new->name, *lst);
	if (old)
	{
		free(old->value);
		if (new->value)
			old->value = ft_strdup(new->value);
		else
			old->value = NULL;
		var_lst_delete_node(new);
		return ;
	}
	var_lst_add_front(lst, new);
}
