/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:32:51 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/05 01:10:40 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

# define BUILDS_COUNT 7
# define BUILTIN_MISUSE_CODE 2

void	ft_echo(char *usr_in, int write_fd);
void	ft_env(int write_fd);
void	ft_pwd(int write_fd);
void	ft_cd(char *usr_in);
void	ft_exit(char *usr_in, t_pipe *pipe_lst, t_builtin *builds,
			t_bool print);
void	ft_export(char *usr_in, int write_fd);
void	ft_unset(char *usr_in);

#endif
