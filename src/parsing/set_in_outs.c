/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_in_outs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:34:01 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/29 06:40:28 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_in_out(t_shell *st_shell)
{
	st_shell->infile = STDIN_FILENO;
	st_shell->outfile = STDOUT_FILENO;
	if (st_shell->lst_size != 1)
	{
		if (st_shell->lst_inx == 1)
		{
			pipe(st_shell->pipe);
			st_shell->outfile = st_shell->pipe[STDOUT_FILENO];
		}
		else if (st_shell->lst_inx != st_shell->lst_size)
		{
			st_shell->infile = st_shell->pipe[STDIN_FILENO];
			close(st_shell->pipe[STDOUT_FILENO]);
			pipe(st_shell->pipe);
			st_shell->outfile = st_shell->pipe[STDOUT_FILENO];
		}
		else
			st_shell->infile = st_shell->pipe[STDIN_FILENO];
	}
}

t_bool	check_file_access(char *file_name, char token)
{
	if (token == '<')
	{
		if (access(file_name, F_OK) != 0)
		{
			error_message(file_name, ERROR_FILE_DIR);
			return (FALSE);
		}
		if (access(file_name, X_OK) != 0)
		{
			error_message(file_name, ERROR_PERMI);
			return (FALSE);
		}
		token_lst->infile = open(file_name, O_RDWR);
	}
	else if (token == '>')
		token_lst->outfile = open(file_name, O_TRUNC | O_RDWR | O_CREAT, 0644);
	return (TRUE);
}

t_bool	check_file_name(char *file, int *str_inx, char token)
{
	int		file_inx;
	char	*unquoted;

	file_inx = 0;
	while (ft_isprint(file_name[file_inx]) && file_name[file_inx] != '\0')
	{
		if (file_name[file_inx == '\'' || file_name[file_inx] == '\"'])
			quit_quote(file_name, &file_inx);
		if (ft_strchr("<>$ ", file_name[file_inx]))
			break ;
		file_inx++;
	}
	unquoted = remove_quotes_from_word(file_name, file_inx);
	*str_inx += file_inx;
	return (check_file_access(unquote, token));
}



t_bool	reconize_redirect(t_type *token_lst, t_shell *st_shell)
{
	int		inx;
	int		inx_start;
	char	token;

	inx = 0;
	while (token_lst->str[inx])
	{
		if (token_lst->str[inx] == '\'' || token_lst->str[inx] == '\"')
			quit_quote(token_lst->str, &inx);
		else if (ft_strchr("<>", token_lst->str[inx]))
		{
			inx_start = inx;
			token = token_lst->str[inx];
			while (ft_isspace(file_name[inx]))
				inx++;
			if (file_name[inx] == '\0')
			{
				ft_putstr_fd(LULUSHELL_ERROR, 2);
				ft_putendl_fd(SYNTAX_ERROR, 2);
				return (FALSE);
			}
			if (check_file(&token_lst->str[inx], &inx, token) == FALSE)
				return (FALSE);
			else

		}
		inx++;
	}
}
