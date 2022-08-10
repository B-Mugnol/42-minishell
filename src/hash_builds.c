/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_builds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:59:12 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/09 21:00:11 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	hash_search(const char *key, t_var *env)
{
	t_builtin	builds[2];
	size_t		size;
	size_t		inx;

	builds[0] = (t_builtin){"pwd", (void *)ft_pwd};
	builds[1] = (t_builtin){"env", (void *)ft_env};
	size = sizeof(builds) / sizeof(t_builtin);
	inx = 0;
	while (inx < size)
	{
		if (ft_strncmp(builds[inx].name, key, ft_strlen(builds[inx].name)) == 0)
		{
			if (inx == 0)
				builds[inx].func(NULL);
			else if (inx == 1)
				builds[inx].func(env);
			return (TRUE);
		}
		inx++;
	}
	return (FALSE);
}
