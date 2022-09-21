/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:29:50 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/21 22:46:05 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**get_environment(void);

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

void	fork_exec(t_shell *st_shell, t_type *token_lst)
{
	int		pid;
	char	**envp;

	envp = get_environment();
	if (recognizer_cmd(token_lst, st_shell) == FALSE)
		return (set_exit_status(127));
	pid = fork();
	if (pid == 0)
		exec(st_shell, envp);
	if (st_shell->lst_inx == st_shell->lst_size)
		close_pipes(st_shell);
	waitpid(pid, NULL, 0);
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
