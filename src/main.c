/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:53:02 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/15 05:24:01 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_node		*env_lst;
	char		*std_in;
	char		*shell_name;

	shell_name = "luluShell>";
	env_lst = set_node();
	printf("%s\n", get_comman("ls", env_lst));
	while (1)
	{
		std_in = readline(shell_name);
		add_history(std_in);
	}
	lst_clear(&env_lst);
	return (0);
}
