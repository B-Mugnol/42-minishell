/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_lst_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:23:28 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/02 20:36:21 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_lst.h"

void	pipe_lst_delete_node(t_pipe *node)
{
	if (!node)
		return ;
	free(node->str);
	free(node);
}

void	pipe_lst_clear(t_pipe **lst)
{
	t_pipe	*acc;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		acc = (*lst)->next;
		pipe_lst_delete_node(*lst);
		*lst = acc;
	}
	*lst = NULL;
}
