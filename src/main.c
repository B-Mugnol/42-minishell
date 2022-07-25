/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:53:02 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/25 23:24:01 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_var	*env_lst;
	t_var	*var_lst;
	char	*std_in;
	char	*shell_name;

	shell_name = "luluShell>";
	var_lst = set_node();
	set_exit_status(&var_lst, EXIT_SUCCESS);
	ft_env(var_lst);
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
		free(std_in);
	}
	rl_clear_history();
	lst_clear(&env_lst);
	lst_clear(&var_lst);
	return (0);
}

void	set_exit_status(t_var**var_lst, int exit_status)
{
	lst_add_var(var_lst, lst_new(ft_strdup("?"), ft_itoa(exit_status)));
}
