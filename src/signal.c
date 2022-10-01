/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 04:00:30 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/02 01:12:07 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

static void	signal_handler(int signal);
static void	child_signal_handler(int signal);

void	sig_setup(void)
{
	struct sigaction	int_action;
	struct sigaction	quit_action;

	ft_bzero(&int_action, sizeof(struct sigaction));
	ft_bzero(&quit_action, sizeof(struct sigaction));
	sigemptyset(&int_action.sa_mask);
	sigemptyset(&quit_action.sa_mask);
	int_action.sa_handler = signal_handler;
	quit_action.sa_handler = SIG_IGN;
	sigaction(SIGINT, &int_action, NULL);
	sigaction(SIGQUIT, &quit_action, NULL);
}

void	child_sig_setup(void)
{
	struct sigaction	action;

	ft_bzero(&action, sizeof(struct sigaction));
	sigemptyset(&action.sa_mask);
	action.sa_handler = child_signal_handler;
	sigaction(SIGINT, &action, NULL);
	sigaction(SIGQUIT, &action, NULL);
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
	if (signal == SIGQUIT)
		return (ft_putendl_fd("Quit (core dumped)", 1));
	if (signal != SIGINT)
		return ;
	set_exit_status(130);
	ft_putchar_fd('\n', 1);
}
