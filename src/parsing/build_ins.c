/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:05:56 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/06 22:46:02 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	recognize_builds(char *usr_in, t_builtin *builds)
{
	char		**words;
	int			build_inx;
	int			inx;

	inx = 0;
	words = ft_word_split(usr_in, ft_isspace);
	if (!words)
		return (7);
	while (words[inx])
	{
		build_inx = hash_search(words[inx], builds);
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

void	exec_builds(t_builtin *builds, int build_inx, char *usr_input)
{
	if (build_inx == 1 || build_inx == 2 || build_inx == 4)
		builds[build_inx].func();
	else
		builds[build_inx].func(usr_input);
}

t_bool	builds(t_type *token_lst, t_shell *st_shell)
{
	int			build_inx;
	char		*tmp;
	t_builtin	*builds;

	tmp = token_lst->str;
	token_lst->str = remove_quotes_from_word(tmp, ft_strlen(token_lst->str));
	free(tmp);
	builds = init_builds();
	build_inx = recognize_builds(token_lst->str, builds);
	if (build_inx != 7)
	{
		if (valid_hash(build_inx, st_shell->lst_size) == FALSE)
		{
			free(builds);
			return (FALSE);
		}
		else
			exec_builds(builds, build_inx, token_lst->str);
	}
	free(builds);
	return (TRUE);
}