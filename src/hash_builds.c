/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_builds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:59:12 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/19 07:09:44 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin	*init_builds(void)
{
	t_builtin	*builds;

	builds = malloc(sizeof(t_builtin) * 7);
	builds[0] = (t_builtin){"cd", (void *)ft_cd};
	builds[1] = (t_builtin){"echo"};
	builds[2] = (t_builtin){"env", (void *)ft_env};
	builds[3] = (t_builtin){"exit"};
	builds[4] = (t_builtin){"export", (void *)ft_export};
	builds[5] = (t_builtin){"pwd", (void *)ft_pwd};
	builds[6] = (t_builtin){"unset", (void *)ft_unset};
	return (builds);
}

char	*hash_search(const char *key, t_builtin *builds)
{
	size_t		inx;

	inx = 0;
	while (inx < 7)
	{
		if (ft_strncmp(builds[inx].name, key, ft_strlen(builds[inx].name)) == 0)
			return (builds[inx].name);
		inx++;
	}
	return (NULL);
}

char	*search_valid_hash(char *build)
{
	char	**builds_lst;
	int		inx;

	builds_lst = ft_word_split("env pwd echo", ft_isspace);
	while (builds_lst[inx])
	{
		if (ft_strncmp(build, builds_lst[inx], ft_strlen(builds_lst[inx]) == 0))
			return (build);
		inx++;
	}
	return (NULL);
}
