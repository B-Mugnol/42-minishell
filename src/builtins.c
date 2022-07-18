/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:23:34 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/07/18 16:07:48 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 'env' does not work if PATH var is unset.
void	ft_env(t_node *env_lst)
{
	if (!env_lst || !find_var("PATH", env_lst))
		return ;
	while (env_lst)
	{
		printf("%s=%s", env_lst->name, env_lst->value);
		env_lst = env_lst->next;
		if (env_lst)
			printf("\n");
	}
}

// 'pwd' works even if the vars PWD and PATH are unset.
void	ft_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	printf("%s\n", path);
	free(path);
}
