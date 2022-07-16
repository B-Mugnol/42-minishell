/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:01:12 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/15 22:30:55 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_node	*lst_new(char *name, char *value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->name = name;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	lst_add_back(t_node **lst, t_node *new)
{
	t_node	*head;

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

void	lst_add_front(t_node **lst, t_node *new)
{
	if (!*lst)
		*lst = new;
	new->next = *lst;
	*lst = new;
}

void	lst_add_var(t_node **lst, t_node *new)
{
	t_node	*old;

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

t_node	*find_var(char *name, t_node *lst)
{
	while (lst)
	{
		if (ft_strncmp(name, lst->name, ft_strlen(name) + 1) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
