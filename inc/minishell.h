/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:40:30 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/06 20:52:52 by llopes-n         ###   ########.fr       */
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

void		init(void);
void		get_comman(char *usr_in, t_shell *comman);
void		exec(int fd_in, int fd_out, t_shell *comman);
void		set_exit_status(int exit_status);
t_var		**set_node(void);

// signal.c
void		sig_setup(void);

// builds
t_bool		builds(t_type *token_lst, t_shell *st_shell);
t_builtin	*init_builds(void);
int			hash_search(const char *key, t_builtin *builds);
t_bool		valid_hash(int build_inx, int lst_size);

#endif
