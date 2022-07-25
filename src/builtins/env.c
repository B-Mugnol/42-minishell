/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:49:39 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/07/26 00:04:35 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_var *env_lst)
{
	if (!env_lst || !find_var("PATH", env_lst))
		return ;
	while (env_lst)
	{
		ft_putstr_fd(env_lst->name, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(env_lst->value, 1);
		env_lst = env_lst->next;
		if (env_lst)
			ft_putchar_fd('\n', 1);
	}
}
