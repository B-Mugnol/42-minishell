/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:40:30 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/04 23:42:52 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define LULUSHELL "luluShell> "

# include "struct.h"
# include "var_lst.h"
# include "pipe_lst.h"
# include "parsing.h"
# include "builtin.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <dirent.h>

extern t_var	**g_env;

int		get_exit_status(void);

void	init(char **envp);
void	get_comman(char *usr_in, t_shell *comman);
void	exec(t_shell *st_shell, char **envp);
void	set_exit_status(int exit_status);
t_var	**set_node(void);

// signal_setup.c
void	sig_setup(void);
void	child_sig_setup(void);
void	heredoc_sig_setup(void);

// signal_handler.c
void	signal_handler(int signal);
void	child_signal_handler(int signal);
void	heredoc_signal_handler(int signal);

// frees_and_closes.c
void	close_fds(t_shell *st_shell);
void	close_pipes(t_shell *st_shell);
void	cmd_error(t_shell *st_shell, char **paths);
void	free_args_error(t_shell *st_shell, char *message);
t_bool	free_return(char *str_free);

// error.c
t_bool	generic_error(int exit_status, char *locale, char *message);
void	pipe_syntax_error(void);
int		error_syntax(char *str);

#endif
