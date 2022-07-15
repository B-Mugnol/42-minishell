/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:01:12 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/15 00:22:43 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*shlst_new(char *name, char *value)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	node->name = name;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	shlst_addback(t_env **lst, t_env *new)
{
	t_env	*head;

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

t_env	*find_env(char *name, t_env *env_lst)
{
	while (env_lst)
	{
		if (ft_strncmp(name, env_lst->name, ft_strlen(name) + 1) == 0)
			return (env_lst);
		env_lst = env_lst->next;
	}
	return (NULL);
}
