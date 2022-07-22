/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:53:02 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/23 00:35:37 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_glo	comman;
	t_node	*env_lst;
	t_node	*var_lst;
	char	*std_in;
	char	*shell_name;

	shell_name = "luluShell>";
	env_lst = set_node();
	var_lst = set_node();
	set_exit_status(&var_lst, EXIT_SUCCESS);
	ft_env(var_lst);
	get_comman("envp", env_lst, &comman);
	printf("%s\n", comman.cmd);
	if (comman.cmd)
		free(comman.cmd);
	sig_setup();
	while (1)
	{
		std_in = readline(shell_name);
		if (std_in == NULL)
		{
			ft_putchar_fd('\n', 1);
			break ;
		}
		hash_search(std_in, env_lst);
		add_history(std_in);
		free(std_in);
	}
	rl_clear_history();
	lst_clear(&env_lst);
	lst_clear(&var_lst);
	return (0);
}

void	set_exit_status(t_node **var_lst, int exit_status)
{
	lst_add_var(var_lst, lst_new(ft_strdup("?"), ft_itoa(exit_status)));
}
