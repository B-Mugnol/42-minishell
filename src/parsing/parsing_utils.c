/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:15:54 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/12 19:20:11 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	quit_quote(char *str, size_t *inx)
{
	char	quote;

	quote = str[*inx];
	*inx = *inx + 1;
	while (str[*inx])
	{
		if (str[*inx] == quote)
			break ;
		*inx += 1;
	}
}

void	replace_token(char *str, char token, char new_value)
{
	size_t	s_quote_count;
	size_t	d_quote_count;

	if (!str)
		return ;
	s_quote_count = 0;
	d_quote_count = 0;
	while (*str)
	{
		if (*str == '\"' && s_quote_count % 2 == 0)
			d_quote_count++;
		if (*str == '\'' && d_quote_count % 2 == 0)
			s_quote_count++;
		if ((s_quote_count % 2 == 1 || d_quote_count % 2 == 1) && *str == token)
			*str = new_value;
		str++;
	}
}

char	*get_var_name(char *post_dollar_str)
{
	size_t	inx;
	char	*var_name;

	inx = 0;
	if (post_dollar_str[inx] == '?')
		return (ft_strdup("?"));
	while (post_dollar_str[inx]
		&& (ft_isalnum(post_dollar_str[inx]) || post_dollar_str[inx] == '_'))
		inx++;
	var_name = ft_substr(post_dollar_str, 0, inx);
	return (var_name);
}

t_bool	is_valid_varname_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (TRUE);
	return (FALSE);
}
