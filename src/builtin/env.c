/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:49:39 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/09/14 20:10:27 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_env(void)
{
	t_var	*iterator;

	iterator = *g_env;
	if (!iterator || !var_lst_find_var("PATH", iterator))
		return ;
	while (iterator)
	{
		if (ft_strncmp(iterator->name, "?", 2) != 0)
		{
			ft_putstr_fd(iterator->name, 1);
			ft_putstr_fd("=", 1);
			ft_putendl_fd(iterator->value, 1);
		}
		iterator = iterator->next;
	}
}
