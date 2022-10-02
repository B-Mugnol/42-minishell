/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 04:00:30 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/02 02:47:21 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

static void	signal_handler(int signal);
static void	child_signal_handler(int signal);

void	sig_setup(void)
{
	struct sigaction	action;

	ft_bzero(&action, sizeof(struct sigaction));
	sigemptyset(&action.sa_mask);
	action.sa_handler = signal_handler;
	sigaction(SIGINT, &action, NULL);
}

void	child_sig_setup(void)
{
	struct sigaction	action;

	ft_bzero(&action, sizeof(struct sigaction));
	sigemptyset(&action.sa_mask);
	action.sa_handler = child_signal_handler;
	sigaction(SIGINT, &action, NULL);
}

static void	signal_handler(int signal)
{
	if (signal != SIGINT)
		return ;
	set_exit_status(130);
	ft_putchar_fd('\n', 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
}

static void	child_signal_handler(int signal)
{
	if (signal != SIGINT)
		return ;
	set_exit_status(130);
	ft_putchar_fd('\n', 1);
}
