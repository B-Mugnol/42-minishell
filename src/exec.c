/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:29:50 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/14 03:58:14 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strnchr(char *str, char c)
{
	size_t	inx;

	inx = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (inx);
		str++;
		inx++;
	}
	return (0);
}

t_env	*set_env(char **env)
{
	t_env	*env_lst;
	char	*name;
	char	*value;

	env_lst = NULL;
	while (*env)
	{
		name = ft_substr(*env, 0, ft_strnchr(*env, '='));
		value = ft_substr(*env, ft_strnchr(*env, '=') + 1, ft_strlen(*env));
		shlst_addback(&env_lst, shlst_new(name, value));
		env++;
	}
	return (env_lst);
}
