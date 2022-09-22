/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:25:57 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/22 20:45:23 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_var	**get_environment_lst(char **envp);

void	init(char **envp)
{
	char	*std_in;
	char	*shell_name;
	t_shell	st_shell;

	shell_name = "luluShell>";
	g_env = get_environment_lst(envp);
	set_exit_status(EXIT_SUCCESS);
	sig_setup();
	while (1)
	{
		std_in = readline(shell_name);
		if (std_in == NULL)
		{
			ft_putendl_fd("exit", 1);
			break ;
		}
		add_history(std_in);
		parsing(std_in, &st_shell);
		free(std_in);
	}
	rl_clear_history();
}

void	set_exit_status(int exit_status)
{
	var_lst_add_var(g_env, var_lst_new(ft_strdup("?"), ft_itoa(exit_status)));
}

static t_var	**get_environment_lst(char **envp)
{
	t_var	**env_lst;
	char	*eq_sign;
	size_t	inx;

	inx = 0;
	env_lst = malloc(sizeof(t_var *));
	*env_lst = NULL;
	while (envp[inx])
	{
		eq_sign = ft_strchr(envp[inx], '=');
		var_lst_add_front(env_lst, var_lst_new(
				ft_substr(envp[inx], 0, eq_sign - envp[inx]),
				ft_substr(eq_sign, 1, ft_strlen(eq_sign + 1))
				));
		inx++;
	}
	return (env_lst);
}
