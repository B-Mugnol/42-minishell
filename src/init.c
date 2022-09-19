/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:25:57 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/15 02:45:49 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(t_shell *st_shell)
{
	g_env = set_node();
	set_exit_status(EXIT_SUCCESS);
	sig_setup();
}

void	set_exit_status(int exit_status)
{
	var_lst_add_var(g_env, var_lst_new(ft_strdup("?"), ft_itoa(exit_status)));
}
