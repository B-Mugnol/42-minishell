/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:53:02 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/20 23:26:43 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var	**g_env;

int	main(void)
{
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
	var_lst_clear(g_env);
	free(g_env);
	return (0);
}
