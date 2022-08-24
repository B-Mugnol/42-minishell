/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_builds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:59:12 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/24 07:26:22 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin	*init_builds(void)
{
	t_builtin	*builds;

	builds = malloc(sizeof(t_builtin) * 7);
	builds[0] = (t_builtin){"cd", (void *)ft_cd};
	builds[1] = (t_builtin){"echo", NULL};
	builds[2] = (t_builtin){"env", (void *)ft_env};
	builds[3] = (t_builtin){"exit", (void *)exit_build};
	builds[4] = (t_builtin){"export", (void *)ft_export};
	builds[5] = (t_builtin){"pwd", (void *)ft_pwd};
	builds[6] = (t_builtin){"unset", (void *)ft_unset};
	return (builds);
}

int	hash_search(const char *key, t_builtin *builds)
{
	size_t		inx;

	inx = 0;
	while (inx < 7)
	{
		if (ft_strncmp(builds[inx].name, key, ft_strlen(builds[inx].name)) == 0)
			return (inx);
		inx++;
	}
	return (NULL);
}

int	search_valid_hash(t_builtin *builds, char *key)
{
	int		inx;

	inx = 0;
	while (inx < 7)
	{
		if (inx == 1 || inx == 2 || inx == 5)
			if (ft_strncmp(builds[inx].name, key, ft_strlen(builds[inx].name)) == 0)
				return (inx);
		inx++;
	}
	return (NULL);
}
