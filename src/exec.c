/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:29:50 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/15 01:05:14 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*set_env(void)
{
	t_env	*env_lst;
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
		shlst_addback(&env_lst, shlst_new(name, value));
		env = get_next_line(fd);
	}
	return (env_lst);
}

char	*get_comman(char *usr_in, t_env *env_lst)
{
	t_env	*path;
	char	**path_comman;
	char	*temp;
	char	*comman;

	path = find_env("PATH", env_lst);
	path_comman = ft_split(path->value, ':');
	while (*path_comman)
	{
		temp = ft_strjoin(*path_comman, "/");
		comman = ft_strjoin(temp, usr_in);
		free(temp);
		if (access(comman, F_OK) == 0)
			return (comman);
		free(comman);
		path_comman++;
	}
	return (NULL);
}
