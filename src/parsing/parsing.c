/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:34:17 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/30 05:36:13 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

void	cmd_recognizer(t_type *token_lst);
void	parsing_loop(t_type *token_lst, t_shell *st_shell);

void	parsing(char *std_in, t_shell *st_shell)
{
	t_type	*token_lst;

	token_lst = tokenizer(std_in, st_shell);
	if (!token_lst)
		return ;
	parsing_loop(token_lst, st_shell);
	type_lst_clear(&token_lst);
}

void	parsing_loop(t_type *token_lst, t_shell *st_shell)
{
	st_shell->lst_inx = 1;
	while (token_lst)
	{
		find_var_and_expand(&token_lst->str, FALSE);
		set_in_out(st_shell);
		if (is_builds(token_lst, st_shell) == FALSE)
		{
			child_sig_setup();
			fork_exec(st_shell, token_lst);
			sig_setup();
		}
		token_lst = token_lst->next;
		st_shell->lst_inx++;
	}
	st_shell->lst_inx = 0;
	while (st_shell->lst_inx < st_shell->lst_size)
	{
		waitpid(-1, NULL, 0);
		st_shell->lst_inx++;
	}
}
