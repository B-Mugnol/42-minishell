/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 01:28:36 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/02 19:53:12 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

void	signal_handler(int signal)
{
	if (signal != SIGINT)
		return ;
	set_exit_status(130);
	ft_putchar_fd('\n', 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	child_signal_handler(int signal)
{
	if (signal == SIGQUIT)
		return (ft_putendl_fd("Quit (core dumped)", 1));
	if (signal != SIGINT)
		return ;
	set_exit_status(130);
	ft_putchar_fd('\n', 1);
}

void	heredoc_signal_handler(int signal)
{
	if (signal != SIGINT)
		return ;
	set_exit_status(130);
	ft_putstr_fd("\1\n", STDIN_FILENO);
}
