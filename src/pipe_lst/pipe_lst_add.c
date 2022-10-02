/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_lst_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:05:24 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/02 20:36:18 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_lst.h"

t_pipe	*pipe_lst_new(char *str_in)
{
	t_pipe	*node;

	node = malloc(sizeof(t_pipe));
	node->str = str_in;
	node->next = NULL;
	return (node);
}

void	pipe_lst_add_back(t_pipe **lst, t_pipe *new)
{
	t_pipe	*head;

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

void	pipe_lst_add_front(t_pipe **lst, t_pipe *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

int	pipe_lst_size(t_pipe *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
