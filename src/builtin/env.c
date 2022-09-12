/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:49:39 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/09/12 18:43:55 by bmugnol-         ###   ########.fr       */
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
			ft_putstr_fd(iterator->value, 1);
		}
		iterator = iterator->next;
		if (iterator && ft_strncmp(iterator->name, "?", 2) != 0)
			ft_putchar_fd('\n', 1);
	}
}
