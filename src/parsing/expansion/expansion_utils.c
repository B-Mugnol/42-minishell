/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:14:51 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/04 22:44:17 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	is_digit_str(const char *str);

t_var	*get_var_from_assignment(char *str)
{
	char	*name;
	char	*value;
	char	*unquoted;

	unquoted = remove_quotes_from_word(str, ft_strlen(str));
	value = ft_strchr(unquoted, '=');
	if (!value)
		return (var_lst_new(unquoted, NULL));
	name = ft_substr(unquoted, 0, value - unquoted);
	value = ft_substr(value, 1, ft_strlen(value + 1));
	find_var_and_expand(&value, TRUE);
	free(unquoted);
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

	if (!str || !*str || is_digit_str(str))
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

static int	is_digit_str(const char *str)
{
	if (!str || !*str || !ft_isdigit(*str))
		return (0);
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
