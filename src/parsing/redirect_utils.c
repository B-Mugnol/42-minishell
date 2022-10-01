/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 01:05:57 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/01 05:29:12 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_str_size(t_type *token_lst, int start_inx, int end_inx)
{
	int	inx;
	int	new_str_size;

	inx = 0;
	new_str_size = 0;
	while (token_lst->str[inx])
	{
		if (inx < start_inx || inx > end_inx)
			new_str_size++;
		inx++;
	}
	return (new_str_size);
}

static void	cut_str(t_type *token_lst, int start_inx, int end_inx)
{
	int		new_str_size;
	int		new_str_inx;
	int		inx;
	char	*new_str;

	new_str_size = count_str_size(token_lst, start_inx, end_inx);
	new_str = ft_calloc(sizeof(char), new_str_size + 1);
	inx = 0;
	new_str_inx = 0;
	while (token_lst->str[inx] != 0 && new_str_size != 0)
	{
		if (inx < start_inx || inx > end_inx)
		{
			new_str[new_str_inx] = token_lst->str[inx];
			new_str_inx++;
		}
		inx++;
	}
	free(token_lst->str);
	token_lst->str = new_str;
}

t_bool	file_name(char *file, size_t *str_inx, t_tokens tk, t_shell *shell)
{
	size_t	file_inx;
	char	*unquoted;

	file_inx = 0;
	while (ft_isprint(file[file_inx]) && file[file_inx] != '\0')
	{
		if (file[file_inx] == '\'' || file[file_inx] == '\"')
			quit_quote(file, &file_inx);
		if (ft_strchr("<>$ ", file[file_inx]) != NULL)
			break ;
		file_inx++;
	}
	unquoted = remove_quotes_from_word(file, file_inx);
	*str_inx += file_inx;
	if (check_file_access(unquoted, tk, shell) == FALSE)
	{
		free(unquoted);
		return (FALSE);
	}
	free(unquoted);
	return (TRUE);
}

t_bool	set_redirect(t_type *token_lst, t_shell *st_shell, size_t inx)
{
	t_tokens	token;
	int			start_inx;

	start_inx = inx;
	if (token_lst->str[inx] == '<')
		token = INFILE;
	else if (token_lst->str[inx] == '>')
		token = OUTFILE;
	else if (token_lst->str[inx] == '>' && token_lst->str[inx + 1] == '>')
	{
		token = APPEND;
		inx++;
	}
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
