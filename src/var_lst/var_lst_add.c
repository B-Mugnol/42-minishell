/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_lst_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:01:12 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/20 00:22:17 by llopes-n         ###   ########.fr       */
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
		*lst = new;
	old = var_lst_find_var(new->name, *lst);
	if (old)
	{
		free(old->value);
		old->value = ft_strdup(new->value);
		var_lst_delete_node(new);
		return ;
	}
	var_lst_add_front(lst, new);
}

t_var	*var_lst_find_var(char *name, t_var *lst)
{
	while (lst)
	{
		if (ft_strncmp(name, lst->name, ft_strlen(name) + 1) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
