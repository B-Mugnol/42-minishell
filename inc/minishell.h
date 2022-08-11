/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:40:30 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/11 02:19:11 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
/*READLINE--GETENV*/
# include "varlst.h"
# include "type_lst.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <signal.h>
# include "libft.h"

typedef struct s_builtin
{
	char	*name;
	void	(*func)();
}	t_builtin;

typedef struct s_glo
{
	char	*cmd;
	char	**args;
	int		pipe[2];
}	t_glo;

typedef enum e_bool
{
	TRUE,
	FALSE
}	t_bool;

void	get_comman(char *usr_in, t_var *env_lst, t_glo *comman);
t_var	*set_node(void);
t_bool	hash_search(const char *key, t_var *env);
void	exec(int fd_in, int fd_out, t_glo *comman);
t_type	*tokenizer(char *usr_in);
void	parsing(char *std_in, t_var *var_lst);
void	quit_quote(char *str, size_t *inx);
void	set_exit_status(t_var **var_lst, int exit_status);
void	expand_usr_in(char	**usr_in, t_var *var_lst);

// builtins.c
void	ft_cd(t_var **env_lst, char *path);
void	ft_env(t_var *env_lst);
void	ft_export(t_var **var_lst, t_var **env_lst, t_var *export);
void	ft_pwd(void);
void	ft_unset(t_var **var_lst, t_var **env_lst, char *var_name);

// signal.c
void	sig_setup(void);

#endif
