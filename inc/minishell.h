/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:40:30 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/30 07:20:53 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define LULUSHELL "luluShell> "

# include "struct.h"
# include "var_lst.h"
# include "type_lst.h"
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

// signal.c
void	sig_setup(void);
void	child_sig_setup(void);

// frees_and_closes.c
void	close_fds(t_shell *st_shell);
void	close_pipes(t_shell *st_shell);
void	cmd_error(t_shell	*st_shell, char	***paths);
void	free_args_error(t_shell *st_shell, char *message);
void	generic_error(int exit_status, char *locale, char *message);

// erro.c
void	error_message(char *error_type, char *erro_message);
t_bool	error_syntax(void);

#endif
