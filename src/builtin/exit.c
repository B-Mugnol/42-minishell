/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:34:05 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/24 23:22:52 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_build(void)
{
	int	exit_status;

	*g_env = var_lst_find_var("?", *(g_env));
	exit_status = ft_atoi((*g_env)->value);
	rl_clear_history();
	var_lst_clear(g_env);
	exit(exit_status);
}
