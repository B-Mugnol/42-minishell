/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:45:37 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/20 22:48:06 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fds(t_shell *st_shell)
{
	close(st_shell->pipe[STDIN_FILENO]);
	close(st_shell->pipe[STDOUT_FILENO]);
}

void	close_pipes(t_shell *st_shell)
{
	close(st_shell->pipe[0]);
	close(st_shell->pipe[1]);
}
