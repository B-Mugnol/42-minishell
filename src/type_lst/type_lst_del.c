/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_lst_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:23:28 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/11 00:38:23 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	typelst_delete_node(t_type *node)
{
	if (!node)
		return ;
	free(node->str);
	free(node);
}

void	typelst_clear(t_type **lst)
{
	t_type	*acc;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		acc = (*lst)->next;
		typelst_delete_node(*lst);
		*lst = acc;
	}
	*lst = NULL;
}
