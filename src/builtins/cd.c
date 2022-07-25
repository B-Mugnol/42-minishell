/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:49:35 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/07/25 19:50:11 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_node **env_lst, char *path)
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
	lst_add_var(env_lst, lst_new(ft_strdup("PWD"), pwd));
}
