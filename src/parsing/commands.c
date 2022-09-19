/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:47:39 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/15 21:06:46 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**set_cmds_paths(void)
{
	t_var	*path;
	char	*paths;

	path = var_lst_find_var("PATH", *g_env);
	path = path->value;
	return (ft_split(path, ':'));
}

void	recognizer_cmd(t_type *token_lst, t_shell *st_shell)
{
	char	**cmds_ad_args;
	char	**cmds_paths;
	char	*cmd;
	char	*tmp;

	cmds_ad_args = ft_word_split(token_lst->str, ft_isspace);
	cmds_paths = set_cmds_paths();
	while (cmds_paths)
	{
		tmp = ft_strjoin(*cmds_paths, "/");
		cmd = ft_strjoin(tmp, cmds_ad_args[0]);
		free(tmp);
		if (access(cmd, F_OK) == 0)
		{
			st_shell->cmd = cmd;
			st_shell->args = cmds_ad_args + 1;
			free(cmd);
			return ;
		}
		free(cmd);
		cmds_paths++;
	}
}

void	set_in_out(t_shell *st_shell)
{
	st_shell->infile = STDIN_FILENO;
	st_shell->outfile = STDOUT_FILENO;
	if (st_shell->lst_size != 1)
	{
		if (st_shell->lst_inx == 1)
		{
			pipe(st_shell->pipe);
			st_shell->outfile = st_shell->pipe[STDOUT_FILENO];
		}
		else if (st_shell->lst_inx != st_shell->lst_size)
		{
			pipe(st_shell->pipe);
			st_shell->infile = st_shell->pipe[STDIN_FILENO];
			st_shell->outfile = st_shell->pipe[STDOUT_FILENO];
		}
		else
		{
			pipe(st_shell->pipe);
			st_shell->infile = st_shell->pipe[STDIN_FILENO];
		}
	}
}
