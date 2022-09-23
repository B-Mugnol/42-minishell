/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:47:39 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/22 23:23:16 by llopes-n         ###   ########.fr       */
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

t_bool	check_paths(t_shell *st_shell)
{
	char	**cmds_paths;
	char	*tmp;
	int		inx;

	cmds_paths = set_cmds_paths();
	inx = 0;
	while (cmds_paths[inx])
	{
		tmp = ft_strjoin(cmds_paths[inx], "/");
		st_shell->cmd = ft_strjoin(tmp, st_shell->args[0]);
		free(tmp);
		if (access(st_shell->cmd, X_OK) == 0)
		{
			ft_free_char_matrix(&cmds_paths);
			return (TRUE);
		}
		free(st_shell->cmd);
		inx++;
	}
	cmd_error(st_shell, &cmds_paths);
	return (FALSE);
}

t_bool	recognizer_cmd(t_type *token_lst, t_shell *st_shell)
{
	st_shell->args = ft_word_split(token_lst->str, ft_isspace);
	if (**st_shell->args == '/' || **st_shell->args == '.')
	{
		if (access(st_shell->args[0], F_OK) != 0)
		{
			free_args_error(st_shell, ERROR_FILE_DIR);
			return (FALSE);
		}
		if (access(st_shell->args[0], X_OK) == 0)
		{
			st_shell->cmd = ft_strdup(st_shell->args[0]);
			return (TRUE);
		}
		else
		{
			free_args_error(st_shell, ERROR_PERMI);
			return (FALSE);
		}
	}
	return (check_paths(st_shell));
}
