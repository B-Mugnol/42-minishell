/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognize_redirects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:34:50 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/02 22:23:18 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	is_dir(char *file)
{
	DIR	*dir;

	dir = opendir(file);
	if (dir)
	{
		closedir(dir);
		generic_error(1, "-", "Is a directory");
		return (TRUE);
	}
	return (FALSE);
}

t_bool	check_file_access(char **file, t_tokens token, t_shell *st_shell)
{
	find_var_and_expand(file, FALSE);
	if (is_dir(*file))
		return (FALSE);
	if (token == INFILE)
	{
		if (access(*file, F_OK) != 0)
			return (generic_error(1, *file, ERROR_FILE_DIR));
		if (access(*file, R_OK) != 0)
			return (generic_error(1, *file, ERROR_PERMI));
		st_shell->infile = open(*file, O_RDWR);
	}
	else if (token == OUTFILE || token == APPEND)
	{
		if (token == APPEND)
			st_shell->outfile = open(*file, O_APPEND | O_RDWR | O_CREAT, 0644);
		else
			st_shell->outfile = open(*file, O_TRUNC | O_RDWR | O_CREAT, 0644);
		if (st_shell->outfile == -1)
			return (generic_error(1, *file, ERROR_PERMI));
	}
	return (TRUE);
}

int	recognize_redirect(t_pipe *pipe_lst, t_shell *st_shell)
{
	size_t	inx;

	inx = 0;
	heredoc_sig_setup();
	if (has_here_doc(pipe_lst, st_shell, inx) == FALSE)
	{
		sig_setup();
		return (-1);
	}
	sig_setup();
	while (pipe_lst->str[inx])
	{
		if (pipe_lst->str[inx] == '\'' || pipe_lst->str[inx] == '\"')
			quit_quote(pipe_lst->str, &inx);
		else if (ft_strchr("<>", pipe_lst->str[inx]))
		{
			if (set_redirect(pipe_lst, st_shell, inx) == FALSE)
				return (EXIT_FAILURE);
			else
				inx = 0;
		}
		inx++;
	}
	return (EXIT_SUCCESS);
}

t_bool	set_redirect(t_pipe *pipe_lst, t_shell *st_shell, size_t inx)
{
	t_tokens	token;
	int			start_inx;

	start_inx = inx;
	token = get_token(pipe_lst->str, &inx);
	inx++;
	if (ft_isspace(pipe_lst->str[inx]) != 0)
		while (ft_isspace(pipe_lst->str[inx]) != 0)
			inx++;
	if (error_syntax(&pipe_lst->str[inx]) == FALSE)
		return (FALSE);
	if (file_name(&pipe_lst->str[inx], &inx, token, st_shell) == FALSE)
		return (FALSE);
	cut_str(pipe_lst, start_inx, inx);
	if (*pipe_lst->str == '\0')
		return (FALSE);
	return (TRUE);
}
