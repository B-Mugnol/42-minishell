/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:49:35 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/19 21:31:46 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_cd(char *path)
{
	int		status;
	char	*pwd;

	status = chdir(path);
	if (status == -1)
	{
		perror(NULL);
		return ;
	}
	pwd = getcwd(NULL, 0);
	var_lst_add_var(g_env, var_lst_new(ft_strdup("PWD"), pwd));
}
