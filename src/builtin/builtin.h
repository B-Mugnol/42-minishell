/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:32:51 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/09/21 19:39:19 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

# define BUILDS_COUNT 7
# define BUILTIN_MISUSE_CODE 2

void	ft_env(void);
void	ft_pwd(void);
void	ft_cd(char *usr_in);
void	ft_exit(char *usr_in, t_type *token_lst, t_builtin *builds);
void	ft_export(char *usr_in);
void	ft_unset(char *usr_in);

#endif
