/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:53:02 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/18 19:59:58 by llopes-n         ###   ########.fr       */
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
	get_comman("ls", env_lst, &comman);
	printf("%s\n", comman.cmd);
	free(comman.cmd);
	while (inx <= 4)
	{
		std_in = readline(shell_name);
		add_history(std_in);
		free(std_in);
		inx++;
	}
	lst_clear(&env_lst);
	return (0);
}
