/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:53:02 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/20 21:04:24 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var	**g_env;

static int	get_exit_code(void);

int	main(void)
{
	int		exit_code;
	char	*std_in;
	char	*shell_name;
	t_shell	st_shell;

	shell_name = "luluShell>";
	init();
	while (1)
	{
		std_in = readline(shell_name);
		if (std_in == NULL)
		{
			ft_putchar_fd('\n', 1);
			break ;
		}
		add_history(std_in);
		parsing(std_in, &st_shell);
		free(std_in);
	}
	rl_clear_history();
	exit_code = get_exit_code();
	var_lst_clear(g_env);
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
