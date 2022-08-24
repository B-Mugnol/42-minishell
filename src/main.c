/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:53:02 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/24 07:16:52 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var	**g_env;

int	main(void)
{
	char	*std_in;
	char	*shell_name;

	shell_name = "luluShell>";
	g_env = set_node();
	set_exit_status(EXIT_SUCCESS);
	sig_setup();
	while (1)
	{
		std_in = readline(shell_name);
		if (std_in == NULL)
		{
			ft_putchar_fd('\n', 1);
			break ;
		}
		add_history(std_in);
		parsing(std_in);
		free(std_in);
	}
	rl_clear_history();
	var_lst_clear(g_env);
	return (0);
}

void	set_exit_status(int exit_status)
{
	var_lst_add_var(g_env, var_lst_new(ft_strdup("?"), ft_itoa(exit_status)));
}
