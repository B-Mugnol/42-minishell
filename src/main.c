/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:53:02 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/15 02:51:43 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_env		*env_lst;
	char		*std_in;
	char		*shell_name;

	shell_name = "luluShell>";
	env_lst = set_env();
	printf("%s\n", get_comman("ls", env_lst));
	while (1)
	{
		std_in = readline(shell_name);
		add_history(std_in);
	}
	return (0);
}
