/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:34:17 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/23 23:37:22 by bmugnol-         ###   ########.fr       */
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
			fork_exec(st_shell, token_lst);
		token_lst = token_lst->next;
		st_shell->lst_inx++;
	}
	st_shell->lst_inx = 0;
}
