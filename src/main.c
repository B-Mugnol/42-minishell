/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:53:02 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/19 22:49:28 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_glo	comman;
	t_node	*env_lst;
	char	*std_in;
	char	*shell_name;
	int		inx;

	inx = 0;
	shell_name = "luluShell>";
	env_lst = set_node();
	get_comman("envp", env_lst, &comman);
	printf("%s\n", comman.cmd);
	if (comman.cmd)
		free(comman.cmd);
	while (inx <= 4)
	{
		std_in = readline(shell_name);
		hash_search(std_in, env_lst);
		add_history(std_in);
		free(std_in);
		inx++;
	}
	rl_clear_history();
	lst_clear(&env_lst);
	return (0);
}
