/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:34:17 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/01 22:02:27 by bmugnol-         ###   ########.fr       */
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
	st_shell->lst_inx = 0;
	while (st_shell->lst_inx < st_shell->lst_size)
	{
		waitpid(-1, NULL, 0);
		st_shell->lst_inx++;
	}
}

void	parsing_loop(t_type *token_lst, t_shell *st_shell)
{
	t_type	*aux;

	st_shell->lst_inx = 1;
	while (token_lst)
	{
		find_var_and_expand(&token_lst->str, FALSE);
		set_in_out(st_shell);
		if (is_empty_str(token_lst->str))
			set_exit_status(EXIT_SUCCESS);
		else if (reconize_redirect(token_lst, st_shell) == TRUE)
		{
			if (is_builds(token_lst, st_shell) == FALSE)
			{
				child_sig_setup();
				fork_exec(st_shell, token_lst);
				sig_setup();
			}
		}
		aux = token_lst;
		token_lst = token_lst->next;
		type_lst_delete_node(aux);
		st_shell->lst_inx++;
	}
}
