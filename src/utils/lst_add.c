/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:01:12 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/15 04:29:21 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*shlst_new(char *name, char *value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->name = name;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	shlst_addback(t_node **lst, t_node *new)
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

void	shlst_add_front(t_node **lst, t_node *new)
{
	if (!*lst)
		*lst = new;
	new->next = *lst;
	*lst = new;
}

void	shlst_add_var(t_node **lst, t_node *new)
{
	t_node	*old;

	if (!*lst)
		*lst = new;
	old = find_var(new->name, *lst);
	if (old)
	{
		old->value = new->value;
		lst_delete_node(new);
		return ;
	}
	shlst_addfront(lst, new);
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
