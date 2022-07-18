/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:29:50 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/18 19:45:59 by llopes-n         ###   ########.fr       */
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
		value = ft_substr(env, ft_strnchr(env, '=') + 1, ft_strlen(env));
		lst_add_back(&env_lst, lst_new(name, value));
		free(env);
		env = get_next_line(fd);
	}
	return (env_lst);
}

void	get_comman(char *usr_in, t_node *env_lst, t_glo *comman)
{
	t_node	*path;
	char	**path_comman;
	char	*temp;
	int		inx;

	path = find_var("PATH", env_lst);
	comman->cmd = NULL;
	path_comman = ft_split(path->value, ':');
	inx = 0;
	while (path_comman[inx])
	{
		temp = ft_strjoin(path_comman[inx], "/");
		comman->cmd = ft_strjoin(temp, usr_in);
		free(temp);
		if (access(comman->cmd, F_OK) == 0)
		{
			ft_free_char_matrix(&path_comman);
			return ;
		}
		free(comman->cmd);
		inx++;
	}
	ft_free_char_matrix(&path_comman);
}
