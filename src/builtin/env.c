/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:49:39 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/19 21:32:33 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_env(void)
{
	if (!(*g_env) || !var_lst_find_var("PATH", (*g_env)))
		return ;
	while ((*g_env))
	{
		if (ft_strncmp((*g_env)->name, "?", 2) != 0)
		{
			ft_putstr_fd((*g_env)->name, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd((*g_env)->value, 1);
		}
		(*g_env) = (*g_env)->next;
		if ((*g_env))
			ft_putchar_fd('\n', 1);
	}
}
