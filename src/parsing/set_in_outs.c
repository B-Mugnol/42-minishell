/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_in_outs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:34:01 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/23 20:43:04 by llopes-n         ###   ########.fr       */
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
			st_shell->outfile = st_shell->pipe[STDOUT_FILENO];
		}
		else
			st_shell->infile = st_shell->pipe[STDIN_FILENO];
	}
}

char	*check_file_name(char *file_name)
{
	int	inx;

	inx = 0;
	while (ft_isprint(file_name[inx]))
	{
		if (ft_strchr("<>"))
	}
}

t_bool	check_file(t_shell *st_shell, t_type *token_lst, int *inx)
{
	while (ft_isspace(token_lst->str[*inx]))
		*inx++;
	if (token_lst->str[*inx] == '\0')
	{
		ft_putstr_fd(LULUSHELL_ERROR, 2);
		ft_putendl_fd(SYNTAX_ERROR, 2);
	}
	while (ft_isalnum(token_lst->str[*inx]))
	{
		
	}
}

t_bool	reconize_redirect(t_type *token_lst, t_shell *st_shell)
{
	int		inx;

	inx = 0;
	while (token_lst->str[inx])
	{
		if (token_lst->str[inx] == '\'' || token_lst->str[inx] == '\"')
			quit_quote(token_lst->str, &inx);
		else if (ft_strchr("<>", token_lst->str[inx]))
		{
			inx++;
			if (check_file == FALSE)
				return (FALSE);
		}
		inx++;
	}
}
