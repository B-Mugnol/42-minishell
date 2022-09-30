/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:12:18 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/01 02:46:14 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_message(char *error_type, char *error_message)
{
	ft_putstr_fd(LULUSHELL_ERROR, 2);
	ft_putstr_fd(error_type, 2);
	ft_putendl_fd(error_message, 2);
}

t_bool	error_syntax(void)
{
	ft_putstr_fd(LULUSHELL_ERROR, 2);
	ft_putendl_fd(SYNTAX_ERROR, 2);
	set_exit_status(2);
	return (FALSE);
}
