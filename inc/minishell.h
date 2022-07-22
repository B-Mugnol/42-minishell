/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:40:30 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/23 00:34:58 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
/*READLINE--GETENV*/
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include <fcntl.h>
# include "lst.h"

typedef struct s_buildin
{
	char	*name;
	void	(*func)(void *);
}	t_buildin;

typedef struct s_glo
{
	char	*cmd;
	char	**args;
}	t_glo;

typedef enum e_bool
{
	TRUE,
	FALSE
}	t_bool;

void	get_comman(char *usr_in, t_node *env_lst, t_glo *comman);
t_node	*set_node(void);
t_bool	hash_search(const char *key, t_node *env);

void	set_exit_status(t_node **var_lst, int exit_status);

// builtins.c
void	ft_cd(t_node **env_lst, char *path);
void	ft_env(t_node *env_lst);
void	ft_export(t_node **var_lst, t_node **env_lst, t_node *export);
void	ft_pwd(void);
void	ft_unset(t_node **var_lst, t_node **env_lst, char *var_name);

// signal.c
void	sig_setup(void);

#endif
