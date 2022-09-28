/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:05:56 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/24 00:59:46 by bmugnol-         ###   ########.fr       */
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

void	fork_exec_builds(t_builtin *builds, int build_inx, t_type *token_lst,
	t_shell *st_shell)
{
	int			pid;
	int			exit_status;

	pid = fork();
	if (pid == 0)
	{
		dup2(st_shell->infile, STDIN_FILENO);
		dup2(st_shell->outfile, STDOUT_FILENO);
		close_fds(st_shell);
		exec_builds(builds, build_inx, token_lst);
		ft_exit("exit", token_lst, builds);
	}
	if (st_shell->lst_inx == st_shell->lst_size)
	{
		close_pipes(st_shell);
		waitpid(pid, &exit_status, 0);
		set_exit_status(WEXITSTATUS(exit_status));
	}
}

t_bool	is_builds(t_type *token_lst, t_shell *st_shell)
{
	int			build_inx;
	t_builtin	*builds;

	builds = init_builds();
	build_inx = recognize_builds(token_lst->str, builds);
	if (build_inx == 7)
	{
		free(builds);
		return (FALSE);
	}
	if (st_shell->lst_size == 1)
		exec_builds(builds, build_inx, token_lst);
	else
		fork_exec_builds(builds, build_inx, token_lst, st_shell);
	return (TRUE);
}
