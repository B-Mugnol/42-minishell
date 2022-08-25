/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:14:51 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/26 01:37:05 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_var	*get_var_from_assignment(char *str)
{
	char	*name;
	char	*value;

	value = ft_strchr(str, '=');
	if (!value)
		return (var_lst_new(
				remove_quotes_from_word(str, ft_strlen(str)), NULL));
	name = remove_quotes_from_word(str, value - str - 1);
	value = remove_quotes_from_word(value + 1, ft_strlen(value + 1));
	find_var_and_expand(&value, TRUE);
	return (var_lst_new(name, value));
}

char	*get_var_name(char *str)
{
	size_t	inx;

	if (*str == '?')
		return (ft_strdup("?"));
	inx = 0;
	while (str[inx] && is_valid_varname_char(str[inx]))
		inx++;
	if (inx == 0)
		return (NULL);
	return (ft_substr(str, 0, inx));
}

t_bool	is_valid_varname(char *str)
{
	size_t	inx;

	if (!str)
		return (FALSE);
	inx = 0;
	while (str[inx] && str[inx] != '=')
	{
		if ((str[inx] == '\'' || str[inx] == '"'))
		{
			if (is_within_quotes(str, inx))
				return (FALSE);
		}
		else if (!is_valid_varname_char(str[inx]))
			return (FALSE);
		inx++;
	}
	return (TRUE);
}

t_bool	is_valid_varname_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (TRUE);
	return (FALSE);
}
