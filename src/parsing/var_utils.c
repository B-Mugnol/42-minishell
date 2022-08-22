/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:14:51 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/22 18:42:58 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_var	*get_var_from_assignment(char *str)
{
	t_var	*var;
	char	*name;
	char	*value;

	value = ft_strchr(str, '=');
	if (!value)
		return (var_lst_new(ft_strdup(str), NULL));
	name = ft_substr(str, 0, value - str - 1);
	value = ft_substr(value + 1, 0, ft_strlen(value + 1));
	find_var_and_expand(&value);
	return (var_lst_new(name, value));
}

char	*get_var_name_to_expand(char *str)
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
	if (!str)
		return (FALSE);
	while (*str && *str != '=')
	{
		if (!is_valid_varname_char(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

t_bool	is_valid_varname_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (TRUE);
	return (FALSE);
}
