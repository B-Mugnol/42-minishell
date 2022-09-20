/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:47:39 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/20 23:13:54 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**set_cmds_paths(void)
{
	t_var	*path;
	char	*paths;

	path = var_lst_find_var("PATH", *g_env);
	paths = path->value;
	return (ft_split(paths, ':'));
}

t_bool	recognizer_cmd(t_type *token_lst, t_shell *st_shell)
{
	char	**cmds_paths;
	char	*tmp;
	int		inx;

	st_shell->args = ft_word_split(token_lst->str, ft_isspace);
	cmds_paths = set_cmds_paths();
	inx = 0;
	while (cmds_paths[inx])
	{
		tmp = ft_strjoin(cmds_paths[inx], "/");
		st_shell->cmd = ft_strjoin(tmp, st_shell->args[0]);
		free(tmp);
		if (access(st_shell->cmd, F_OK) == 0)
		{
			ft_free_char_matrix(&cmds_paths);
			return (TRUE);
		}
		free(st_shell->cmd);
		inx++;
	}
	ft_putstr_fd(st_shell->args[0], STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	ft_free_char_matrix(&st_shell->args);
	ft_free_char_matrix(&cmds_paths);
	return (FALSE);
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
			st_shell->infile = st_shell->pipe[STDIN_FILENO];
			st_shell->outfile = st_shell->pipe[STDOUT_FILENO];
		}
		else
			st_shell->infile = st_shell->pipe[STDIN_FILENO];
	}
}
