/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_in_outs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:34:01 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/02 00:31:33 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	set_redirect(t_type *token_lst, t_shell *st_shell, size_t inx);
static void		get_here_doc(t_type *token_lst, t_shell *st_shell, size_t inx);

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
	get_here_doc(token_lst, st_shell, inx);
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

static t_bool	set_redirect(t_type *token_lst, t_shell *st_shell, size_t inx)
{
	t_tokens	token;
	int			start_inx;

	start_inx = inx;
	token = get_token(token_lst->str, &inx);
	inx++;
	while (ft_isspace(token_lst->str[inx]) != 0)
		inx++;
	if (token_lst->str[inx] == '\0')
		return (error_syntax());
	if (file_name(&token_lst->str[inx], &inx, token, st_shell) == FALSE)
		return (FALSE);
	cut_str(token_lst, start_inx, inx);
	if (*token_lst->str == '\0')
		return (FALSE);
	return (TRUE);
}

static void	get_here_doc(t_type *token_lst, t_shell *st_shell, size_t inx)
{
	char	*tk;

	if (inx >= ft_strlen(token_lst->str))
		return ;
	tk = ft_strnstr(token_lst->str + inx, "<<",
			ft_strlen(token_lst->str + inx));
	if (!tk)
		return ;
	inx = tk - token_lst->str;
	if (!is_within_quotes(token_lst->str, inx))
		set_redirect(token_lst, st_shell, inx);
	else
		get_here_doc(token_lst, st_shell, inx + 1);
}
