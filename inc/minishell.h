/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:40:30 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/19 21:48:08 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

extern t_var	**g_env;

void		get_comman(char *usr_in, t_glo *comman);
void		exec(int fd_in, int fd_out, t_glo *comman);
void		set_exit_status(int exit_status);
t_var		**set_node(void);

// signal.c
void		sig_setup(void);

// builds.c
t_builtin	*init_builds(void);
char		*hash_search(const char *key, t_builtin *builds);
char		*search_valid_hash(char *build);

#endif
