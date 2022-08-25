/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:32:51 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/25 23:52:25 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

# define BUILDS_COUNT 7

void	ft_cd(char *path);
void	ft_env(void);
void	ft_export(char *usr_in);
void	ft_pwd(void);
void	ft_unset(char *var_name);

#endif
