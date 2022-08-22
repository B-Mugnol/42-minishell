/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:14:51 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/22 16:17:52 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
