/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_and_closes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:45:37 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/30 03:23:50 by bmugnol-         ###   ########.fr       */
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
	ft_putstr_fd("luluShell: ", STDERR_FILENO);
	ft_putstr_fd(st_shell->args[0], STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	ft_free_char_matrix(&st_shell->args);
	ft_free_char_matrix(paths);
}

void	free_args_error(t_shell *st_shell, char *message)
{
	ft_putstr_fd("luluShell: ", STDERR_FILENO);
	ft_putstr_fd(st_shell->args[0], STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	ft_free_char_matrix(&st_shell->args);
}

void	generic_error(int exit_status, char *locale, char *message)
{
	ft_putstr_fd("luluShell: ", STDERR_FILENO);
	if (locale)
	{
		ft_putstr_fd(locale, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putendl_fd(message, STDERR_FILENO);
	set_exit_status(exit_status);
}
