/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 01:05:57 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/02 06:21:39 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_str_size(t_type *token_lst, int start_inx, int end_inx)
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

void	cut_str(t_type *token_lst, int start_inx, int end_inx)
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
		if (ft_strchr("<> ", file[file_inx]) != NULL)
			break ;
		file_inx++;
	}
	unquoted = remove_quotes_from_word(file, file_inx);
	*str_inx += file_inx;
	if ((tk == HEREDOC && here_doc(unquoted, shell) == FALSE)
		|| check_file_access(&unquoted, tk, shell) == FALSE)
	{
		free(unquoted);
		return (FALSE);
	}
	free(unquoted);
	return (TRUE);
}

t_tokens	get_token(char *str, size_t *inx)
{
	if (str[*inx] == '>' && str[*inx + 1] == '>')
	{
		(*inx)++;
		return (APPEND);
	}
	else if (str[*inx] == '<' && str[*inx + 1] == '<')
	{
		(*inx)++;
		return (HEREDOC);
	}
	else if (str[*inx] == '<')
		return (INFILE);
	else if (str[*inx] == '>')
		return (OUTFILE);
	return (NOT_REDIR);
}
