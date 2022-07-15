/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:01:12 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/15 03:36:38 by bmugnol-         ###   ########.fr       */
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

t_node	*find_env(char *name, t_node *env_lst)
{
	while (env_lst)
	{
		if (ft_strncmp(name, env_lst->name, ft_strlen(name) + 1) == 0)
			return (env_lst);
		env_lst = env_lst->next;
	}
	return (NULL);
}
