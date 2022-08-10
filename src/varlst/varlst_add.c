/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varlst_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:01:12 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/09 21:01:15 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "varlst.h"

t_var	*varlst_new(char *name, char *value)
{
	t_var	*node;

	node = malloc(sizeof(t_var));
	node->name = name;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	varlst_add_back(t_var **lst, t_var *new)
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

void	varlst_add_front(t_var **lst, t_var *new)
{
	if (!*lst)
		*lst = new;
	new->next = *lst;
	*lst = new;
}

void	varlst_add_var(t_var **lst, t_var *new)
{
	t_var	*old;

	if (!*lst)
		*lst = new;
	old = varlst_find_var(new->name, *lst);
	if (old)
	{
		free(old->value);
		old->value = ft_strdup(new->value);
		varlst_delete_node(new);
		return ;
	}
	varlst_add_front(lst, new);
}

t_var	*varlst_find_var(char *name, t_var *lst)
{
	while (lst)
	{
		if (ft_strncmp(name, lst->name, ft_strlen(name) + 1) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
