/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:29:50 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/23 01:16:27 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*set_node(void)
{
	t_node	*env_lst;
	char	*env;
	char	*name;
	char	*value;
	int		fd;

	fd = open("/etc/environment", O_RDONLY);
	env = get_next_line(fd);
	env_lst = NULL;
	while (env)
	{
		name = ft_substr(env, 0, ft_strnchr(env, '='));
		value = ft_substr(env, ft_strnchr(env, '=') + 2,
				ft_strlen(env) - (ft_strnchr(env, '=') + 2) - 2);
		lst_add_back(&env_lst, lst_new(name, value));
		free(env);
		env = get_next_line(fd);
	}
	return (env_lst);
}

void	get_comman(char *usr_in, t_node *env_lst, t_glo *comman)
{
	t_node	*path;
	char	**path_cmd;
	char	*temp;
	int		inx;

	path = find_var("PATH", env_lst);
	path_cmd = ft_split(path->value, ':');
	inx = 0;
	while (path_cmd[inx])
	{
		temp = ft_strjoin(path_cmd[inx], "/");
		comman->cmd = ft_strjoin(temp, usr_in);
		free(temp);
		if (access(comman->cmd, F_OK) == 0)
		{
			ft_free_char_matrix(&path_cmd);
			return ;
		}
		free(comman->cmd);
		comman->cmd = NULL;
		inx++;
	}
	ft_free_char_matrix(&path_cmd);
}

void	child(int fd_in, int fd_out, t_glo *comman)
{
	dup2(fd_out, STDOUT_FILENO);
	dup2(fd_in, STDIN_FILENO);
	execve(comman->cmd, comman->args, NULL);
}
