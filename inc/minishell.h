/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:40:30 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/19 07:09:56 by llopes-n         ###   ########.fr       */
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
# include <signal.h>

void		get_comman(char *usr_in, t_var *env_lst, t_glo *comman);
void		exec(int fd_in, int fd_out, t_glo *comman);
void		set_exit_status(t_var **var_lst, int exit_status);
t_var		*set_node(void);

// signal.c
void		sig_setup(void);

// builds.c
t_builtin	*init_builds(void);
char		*hash_search(const char *key, t_builtin *builds);
char		*search_valid_hash(char *build);

#endif
