/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:32:51 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/12 20:02:01 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

void	ft_cd(t_var **env_lst, char *path);
void	ft_env(t_var *env_lst);
void	ft_export(t_var **var_lst, t_var **env_lst, t_var *export);
void	ft_pwd(void);
void	ft_unset(t_var **var_lst, t_var **env_lst, char *var_name);

#endif
