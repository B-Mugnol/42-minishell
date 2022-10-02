/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:34:17 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/02 20:13:43 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

void	cmd_recognizer(t_pipe *pipe_lst);
void	parsing_loop(t_pipe *pipe_lst, t_shell *st_shell);

void	parsing(char *std_in, t_shell *st_shell)
{
	t_pipe	*pipe_lst;

	pipe_lst = pipe_parse(std_in, st_shell);
	if (!pipe_lst)
		return ;
	st_shell->lst_inx = 1;
	parsing_loop(pipe_lst, st_shell);
	st_shell->lst_inx = 1;
	while (st_shell->lst_inx <= st_shell->lst_size)
	{
		waitpid(-1, NULL, 0);
		st_shell->lst_inx++;
	}
}

void	parsing_loop(t_pipe *pipe_lst, t_shell *st_shell)
{
	t_pipe	*aux;
	int		stat;

	while (pipe_lst)
	{
		set_in_out(st_shell);
		if (is_empty_str(pipe_lst->str))
			set_exit_status(EXIT_SUCCESS);
		else
		{
			stat = recognize_redirect(pipe_lst, st_shell);
			find_var_and_expand(&pipe_lst->str, FALSE);
			if (stat == EXIT_SUCCESS && is_builds(pipe_lst, st_shell) == FALSE)
			{
				fork_exec(st_shell, pipe_lst);
				sig_setup();
			}
			else if (stat == -1)
				return (pipe_lst_clear(&pipe_lst));
		}
		aux = pipe_lst;
		pipe_lst = pipe_lst->next;
		pipe_lst_delete_node(aux);
		st_shell->lst_inx++;
	}
}
