/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:01:12 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/25 23:29:56 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_var	*lst_new(char *name, char *value)
{
	t_var	*node;

	node = malloc(sizeof(t_var));
	node->name = name;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	lst_add_back(t_var **lst, t_var *new)
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

void	lst_add_front(t_var **lst, t_var *new)
{
	if (!*lst)
		*lst = new;
	new->next = *lst;
	*lst = new;
}

void	lst_add_var(t_var **lst, t_var *new)
{
	t_var	*old;

	if (!*lst)
		*lst = new;
	old = find_var(new->name, *lst);
	if (old)
	{
		free(old->value);
		old->value = ft_strdup(new->value);
		lst_delete_node(new);
		return ;
	}
	lst_add_front(lst, new);
}

t_var	*find_var(char *name, t_var *lst)
{
	while (lst)
	{
		if (ft_strncmp(name, lst->name, ft_strlen(name) + 1) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
