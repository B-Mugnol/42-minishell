/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:49:39 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/09/21 21:59:56 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_env(void)
{
	t_var	*iterator;

	iterator = *g_env;
	if (!iterator || !var_lst_find_var("PATH", iterator))
	{
		set_exit_status(127);
		return (ft_putendl_fd("env: No such file or directory", 2));
	}
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
	set_exit_status(EXIT_SUCCESS);
}
