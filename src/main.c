/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:53:02 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/14 03:56:51 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_env	*env_lst;
	char	*std_in;
	char	*shell_name;
	int		is_new_line;

	shell_name = "luluShell>";
	printf("%d\n%s\n", argc, *argv);
	env_lst = set_env(envp);
	while (1)
	{
		std_in = readline(shell_name);
		is_new_line = rl_on_new_line();
		printf("%d\n", is_new_line);
		add_history(std_in);
		rl_replace_line("eu gosto de batata", 1);
	}
	return (0);
}
