/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_and_closes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:45:37 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/03 03:49:34 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fds(t_shell *st_shell)
{
	if (st_shell->lst_size != 1)
	{
		if (st_shell->lst_inx == 1)
			close(st_shell->pipe[STDIN_FILENO]);
		if (st_shell->lst_inx == st_shell->lst_size)
			close(st_shell->pipe[STDOUT_FILENO]);
	}
}

void	close_pipes(t_shell *st_shell)
{
	if (st_shell->lst_size != 1)
	{
		close(st_shell->pipe[0]);
		close(st_shell->pipe[1]);
	}
}

void	cmd_error(t_shell *st_shell, char ***paths)
{
	ft_putstr_fd(LULUSHELL_ERROR, STDERR_FILENO);
	ft_putstr_fd(st_shell->args[0], STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	ft_free_char_matrix(&st_shell->args);
	ft_free_char_matrix(paths);
}

void	free_args_error(t_shell *st_shell, char *message)
{
	ft_putstr_fd(LULUSHELL_ERROR, STDERR_FILENO);
	ft_putstr_fd(st_shell->args[0], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	ft_free_char_matrix(&st_shell->args);
}

t_bool	free_return(char *str_free)
{
	free(str_free);
	sig_setup();
	return (FALSE);
}
