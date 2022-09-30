/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:53:02 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/30 00:04:11 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var	**g_env;

static int	get_exit_code(void);

int	main(int argc, char **argv, char **envp)
{
	int		exit_code;

	if (!argv || argc != 1)
		return (EXIT_FAILURE);
	init(envp);
	exit_code = get_exit_code();
	var_lst_clear(g_env);
	free(g_env);
	return (exit_code);
}

static int	get_exit_code(void)
{
	t_var	*current_status;
	int		exit_code;

	current_status = var_lst_find_var("?", *g_env);
	if (!current_status)
		return (EXIT_FAILURE);
	exit_code = ft_atoi(current_status->value);
	return (exit_code);
}
