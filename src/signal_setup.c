/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 04:00:30 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/02 02:40:10 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

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

void	heredoc_sig_setup(void)
{
	struct sigaction	int_action;
	struct sigaction	quit_action;

	ft_bzero(&int_action, sizeof(struct sigaction));
	ft_bzero(&quit_action, sizeof(struct sigaction));
	sigemptyset(&int_action.sa_mask);
	sigemptyset(&quit_action.sa_mask);
	int_action.sa_handler = heredoc_signal_handler;
	quit_action.sa_handler = SIG_IGN;
	sigaction(SIGINT, &int_action, NULL);
	sigaction(SIGQUIT, &quit_action, NULL);
}
