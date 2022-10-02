/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:12:18 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/02 23:42:32 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	error_syntax(char *str)
{
	int	inx;

	inx = 0;
	if (str[inx] == '\0')
	{
		ft_putstr_fd(LULUSHELL_ERROR, 2);
		ft_putstr_fd(SYNTAX_ERROR, 2);
		ft_putendl_fd("`newline'", 2);
		return (FALSE);
	}
	while (str[inx] && str[inx] == ' ')
	{
		if (ft_strchr("<>", str[inx]))
		{
			ft_putstr_fd(LULUSHELL_ERROR, 2);
			ft_putstr_fd(SYNTAX_ERROR, 2);
			ft_putstr_fd("`", 2);
			ft_putchar_fd(str[inx], 2);
			ft_putendl_fd("'", 2);
			return (FALSE);
			set_exit_status(2);
		}
		inx++;
	}
	return (TRUE);
}

t_bool	generic_error(int exit_status, char *locale, char *message)
{
	ft_putstr_fd(LULUSHELL_ERROR, STDERR_FILENO);
	if (locale)
	{
		ft_putstr_fd(locale, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putendl_fd(message, STDERR_FILENO);
	set_exit_status(exit_status);
	return (FALSE);
}
