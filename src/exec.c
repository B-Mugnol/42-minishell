/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:29:50 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/21 23:34:28 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var	**set_node(void)
{
	t_var	**env_lst;
	char	*env;
	char	*name;
	char	*value;
	int		fd;

	fd = open("/etc/environment", O_RDONLY);
	env = get_next_line(fd);
	env_lst = malloc(sizeof(t_var *));
	*env_lst = NULL;
	while (env)
	{
		name = ft_substr(env, 0, ft_strnchr(env, '='));
		value = ft_substr(env, ft_strnchr(env, '=') + 2,
				ft_strlen(env) - (ft_strnchr(env, '=') + 2) - 2);
		var_lst_add_back(env_lst, var_lst_new(name, value));
		free(env);
		env = get_next_line(fd);
	}
	return (env_lst);
}

t_bool	is_dir(t_type *token_lst)
{
	DIR		*dir;
	char	**cmds;

	cmds = ft_word_split(token_lst->str, ft_isspace);
	dir = opendir(cmds[0]);
	if (dir != NULL)
	{
		ft_putstr_fd("luluShell: ", 2);
		ft_putstr_fd(cmds[0], 2);
		ft_putendl_fd(": Is a directory", 2);
		ft_free_char_matrix(&cmds);
		return (TRUE);
	}
	ft_free_char_matrix(&cmds);
	return (FALSE);
}

void	fork_exec(t_shell *st_shell, t_type *token_lst)
{
	int	pid;

	if (is_dir(token_lst) == TRUE)
		return ;
	if (recognizer_cmd(token_lst, st_shell) == FALSE)
		return (set_exit_status(127));
	pid = fork();
	if (pid == 0)
		exec(st_shell);
	if (st_shell->lst_inx == st_shell->lst_size)
		close_pipes(st_shell);
	waitpid(pid, NULL, 0);
	ft_free_char_matrix(&st_shell->args);
	free(st_shell->cmd);
}

void	exec(t_shell *st_shell)
{
	dup2(st_shell->infile, STDIN_FILENO);
	dup2(st_shell->outfile, STDOUT_FILENO);
	close_fds(st_shell);
	execve(st_shell->cmd, st_shell->args, NULL);
}
