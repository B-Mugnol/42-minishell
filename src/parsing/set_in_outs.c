/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_in_outs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:34:01 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/01 04:58:56 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	check_file_access(char *file, t_tokens token, t_shell *st_shell)
{
	if (token == INFILE)
	{
		if (access(file, F_OK) != 0)
			return (generic_error(1, file, ERROR_FILE_DIR));
		if (access(file, R_OK) != 0)
			return (generic_error(1, file, ERROR_PERMI));
		st_shell->infile = open(file, O_RDWR);
	}
	else if (token == OUTFILE || token == APPEND)
	{
		if (token == APPEND)
			st_shell->outfile = open(file, O_APPEND | O_RDWR | O_CREAT, 0644);
		else
			st_shell->outfile = open(file, O_TRUNC | O_RDWR | O_CREAT, 0644);
		if (st_shell->outfile == -1)
			return (generic_error(1, file, ERROR_PERMI));
	}
	return (TRUE);
}

t_bool	reconize_redirect(t_type *token_lst, t_shell *st_shell)
{
	size_t	inx;

	inx = 0;
	while (token_lst->str[inx])
	{
		if (token_lst->str[inx] == '\'' || token_lst->str[inx] == '\"')
			quit_quote(token_lst->str, &inx);
		else if (ft_strchr("<>", token_lst->str[inx]))
		{
			if (set_redirect(token_lst, st_shell, inx) == FALSE)
				return (FALSE);
			else
				inx = 0;
		}
		inx++;
	}
	return (TRUE);
}
