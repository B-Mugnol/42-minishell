/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:05:56 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/21 20:10:28 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	recognize_builds(char *usr_in, t_builtin *builds)
{
	char	**words;
	char	*temp;
	int		build_inx;
	int		inx;

	inx = 0;
	words = ft_word_split(usr_in, ft_isspace);
	if (!words)
		return (7);
	while (words[inx])
	{
		temp = remove_quotes_from_word(words[inx], ft_strlen(words[inx]));
		build_inx = hash_search(temp, builds);
		free(temp);
		if (build_inx != 7)
		{
			ft_free_char_matrix(&words);
			return (build_inx);
		}
		inx++;
	}
	ft_free_char_matrix(&words);
	return (build_inx);
}

void	exec_builds(t_builtin *builds, int build_inx, t_type *token_lst)
{
	if (build_inx == 1 || build_inx == 2)
		builds[build_inx].func();
	else if (build_inx == 4)
		builds[build_inx].func(token_lst->str, token_lst, builds);
	else
		builds[build_inx].func(token_lst->str);
}

t_bool	is_builds(t_type *token_lst, t_shell *st_shell)
{
	int			build_inx;
	t_builtin	*builds;

	builds = init_builds();
	build_inx = recognize_builds(token_lst->str, builds);
	if (build_inx != 7)
	{
		if (valid_hash(build_inx, st_shell->lst_size) == TRUE)
			exec_builds(builds, build_inx, token_lst);
		free(builds);
		return (TRUE);
	}
	free(builds);
	return (FALSE);
}
