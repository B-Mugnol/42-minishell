/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:49:35 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/22 16:09:58 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_cd(char *path)
{
	t_var	*home_dir;
	int		status;
	char	*pwd;

	if (path == NULL)
	{
		home_dir = var_lst_find_var("HOME", *g_env);
		if (!home_dir)
		{
			set_exit_status(1);
			ft_putstr_fd("cd: HOME not set", 2);
			return ;
		}
		path = home_dir->value;
	}
	status = chdir(path);
	pwd = getcwd(NULL, 0);
	if (status == -1 || !pwd)
	{
		set_exit_status(EXIT_FAILURE);
		return (perror(NULL));
	}
	var_lst_add_var(g_env, var_lst_new(ft_strdup("PWD"), pwd));
}
