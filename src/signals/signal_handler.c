/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 01:28:36 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/03 21:36:44 by bmugnol-         ###   ########.fr       */
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
	{
		set_exit_status(131);
		return (ft_putendl_fd("Quit (core dumped)", 1));
	}
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
