/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_in_outs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:34:01 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/30 05:10:20 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	check_file_access(char *file, char token, t_shell *st_shell)
{
	if (token == '<')
	{
		if (access(file, F_OK) != 0)
		{
			error_message(file, ERROR_FILE_DIR);
			return (FALSE);
		}
		if (access(file, R_OK) != 0)
		{
			error_message(file, ERROR_PERMI);
			return (FALSE);
		}
		st_shell->infile = open(file, O_RDWR);
	}
	else if (token == '>')
		st_shell->outfile = open(file, O_TRUNC | O_RDWR | O_CREAT, 0644);
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
