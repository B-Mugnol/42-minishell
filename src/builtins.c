/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:23:34 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/07/25 23:43:06 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 'env' does not work if PATH var is unset.
void	ft_env(t_var *env_lst)
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

void	ft_unset(t_var **var_lst, t_var **env_lst, char *var_name)
{
	if (!var_name || !*var_name)
		return ;
	lst_delete_var(var_lst, var_name);
	lst_delete_var(env_lst, var_name);
}

void	ft_cd(t_var **env_lst, char *path)
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

void	ft_export(t_var **var_lst, t_var **env_lst, t_var *export)
{
	t_var	*var;

	while (export)
	{
		var = find_var(export->name, *var_lst);
		if (ft_strncmp(export->name, "?", ft_strlen("?")) == 0)
			;
		else if (export->value != NULL)
		{
			lst_add_var(var_lst, lst_new(ft_strdup(export->name),
					ft_strdup(export->value)));
			lst_add_var(env_lst, lst_new(ft_strdup(export->name),
					ft_strdup(export->value)));
		}
		else if (var != NULL)
		{
			lst_add_var(env_lst,
				lst_new(ft_strdup(var->name), ft_strdup(var->value)));
		}
		export = export->next;
	}
}
