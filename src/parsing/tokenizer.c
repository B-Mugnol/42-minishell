/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:48:36 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/01 01:42:02 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

static t_bool	is_empty_str(char *usr_in);
static t_bool	has_unclosed_quotes(char *str);

t_type	*tokenizer(char *usr_in, t_shell *st_shell)
{
	t_type	*lst;
	size_t	inx;

	if (is_empty_str(usr_in) || has_unclosed_quotes(usr_in))
		return (NULL);
	lst = NULL;
	inx = 0;
	while (usr_in[inx])
	{
		if (usr_in[inx] == '\"' || usr_in[inx] == '\'')
			quit_quote(usr_in, &inx);
		if (usr_in[inx] == '|')
		{
			type_lst_add_back(&lst,
				type_lst_new(ft_substr(usr_in, 0, inx)));
			usr_in += inx + 1;
			inx = 0;
		}
		inx++;
	}
	type_lst_add_back(&lst, type_lst_new(ft_substr(usr_in, 0, inx)));
	st_shell->lst_size = type_lst_size(lst);
	return (lst);
}

static t_bool	is_empty_str(char *usr_in)
{
	char	*aux;

	aux = ft_strtrim(usr_in, WHITE_SPACE_CHARS);
	if (!aux)
		return (TRUE);
	if (!*aux)
	{
		free(aux);
		return (TRUE);
	}
	free(aux);
	return (FALSE);
}

static t_bool	has_unclosed_quotes(char *str)
{
	size_t	simple_quote_count;
	size_t	double_quote_count;
	size_t	i;

	simple_quote_count = 0;
	double_quote_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"' && simple_quote_count % 2 == 0)
			double_quote_count++;
		if (str[i] == '\'' && double_quote_count % 2 == 0)
			simple_quote_count++;
		i++;
	}
	if (simple_quote_count % 2 == 1 || double_quote_count % 2 == 1)
		return (TRUE);
	return (FALSE);
}
