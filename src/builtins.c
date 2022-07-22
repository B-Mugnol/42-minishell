/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:23:34 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/07/21 20:50:13 by bmugnol-         ###   ########.fr       */
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
		ft_putstr_fd(env_lst->name, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(env_lst->value, 1);
		env_lst = env_lst->next;
		if (env_lst)
			ft_putchar_fd('\n', 1);
	}
}

// 'pwd' works even if the vars PWD and PATH are unset.
void	ft_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putendl_fd(path, 1);
	free(path);
}

void	ft_unset(t_node **var_lst, t_node **env_lst, char *var_name)
{
	if (!var_name || !*var_name)
		return ;
	lst_delete_var(var_lst, var_name);
	lst_delete_var(env_lst, var_name);
}
