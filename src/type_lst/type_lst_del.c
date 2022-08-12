/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_lst_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:23:28 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/12 20:09:29 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_lst.h"

void	type_lst_delete_node(t_type *node)
{
	if (!node)
		return ;
	free(node->str);
	free(node);
}

void	type_lst_clear(t_type **lst)
{
	t_type	*acc;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		acc = (*lst)->next;
		type_lst_delete_node(*lst);
		*lst = acc;
	}
	*lst = NULL;
}
