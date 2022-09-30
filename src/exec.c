/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:29:50 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/30 04:54:27 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**get_environment(void);

t_bool	is_dir(t_type *token_lst)
{
	DIR		*dir;
	char	**cmds;

	cmds = ft_word_split(token_lst->str, ft_isspace);
	dir = opendir(cmds[0]);
	if (dir != NULL)
	{
		closedir(dir);
		if ((ft_strlen(cmds[0]) > 1 && cmds[0][ft_strlen(cmds[0]) - 1] == '/')
			|| (cmds[0][0] == '.' && cmds[0][1] == '/') || cmds[0][0] == '/')
		{
			generic_error(126, cmds[0], "Is a directory");
			ft_free_char_matrix(&cmds);
		}
		else
		{
			ft_free_char_matrix(&cmds);
			return (FALSE);
		}
		return (TRUE);
	}
	ft_free_char_matrix(&cmds);
	return (FALSE);
}

void	fork_exec(t_shell *st_shell, t_type *token_lst)
{
	int		pid;
	int		exit_status;
	char	**envp;

	exit_status = 0;
	if (is_dir(token_lst) == TRUE)
		return ;
	envp = get_environment();
	if (recognizer_cmd(token_lst, st_shell) == FALSE)
		return (ft_free_char_matrix(&envp));
	pid = fork();
	if (pid == 0)
		exec(st_shell, envp);
	if (st_shell->lst_inx == st_shell->lst_size)
	{
		close_pipes(st_shell);
		waitpid(pid, &exit_status, 0);
		if (get_exit_status() != 130)
			set_exit_status(WEXITSTATUS(exit_status));
	}
	ft_free_char_matrix(&envp);
	ft_free_char_matrix(&st_shell->args);
	free(st_shell->cmd);
}

void	exec(t_shell *st_shell, char **envp)
{
	dup2(st_shell->infile, STDIN_FILENO);
	dup2(st_shell->outfile, STDOUT_FILENO);
	close_fds(st_shell);
	execve(st_shell->cmd, st_shell->args, envp);
}

static char	**get_environment(void)
{
	t_var	*iterator;
	size_t	inx;
	char	*aux;
	char	**envp;

	inx = 0;
	iterator = *g_env;
	envp = malloc(var_lst_size(*g_env) * sizeof(char *));
	while (iterator)
	{
		if (ft_strncmp(iterator->name, "?", 2) != 0)
		{
			aux = ft_strjoin(iterator->name, "=");
			envp[inx] = ft_strjoin(aux, iterator->value);
			free(aux);
			inx++;
		}
		iterator = iterator->next;
	}
	envp[inx] = NULL;
	return (envp);
}
