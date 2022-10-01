/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:12:18 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/01 05:00:45 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	error_syntax(void)
{
	ft_putstr_fd(LULUSHELL_ERROR, 2);
	ft_putendl_fd(SYNTAX_ERROR, 2);
	set_exit_status(2);
	return (FALSE);
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
