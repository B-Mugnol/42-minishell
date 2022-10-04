/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:49:39 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/05 00:44:08 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_env(int write_fd)
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
		if (ft_strncmp(iterator->name, "?", 2) != 0 && iterator->value != NULL)
		{
			ft_putstr_fd(iterator->name, write_fd);
			ft_putstr_fd("=", write_fd);
			ft_putendl_fd(iterator->value, write_fd);
		}
		iterator = iterator->next;
	}
	set_exit_status(EXIT_SUCCESS);
}
