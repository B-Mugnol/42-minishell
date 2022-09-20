/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:09:54 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/09/20 23:37:33 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include <sys/wait.h>
# include "var_lst.h"
# include "type_lst.h"

// commands.c
t_bool		recognizer_cmd(t_type *token_lst, t_shell *st_shell);
void		set_in_out(t_shell *st_shell);
void		fork_exec(t_shell *st_shell, t_type *token_lst);

// build_ins.c
t_bool		is_builds(t_type *token_lst, t_shell *st_shell);
t_builtin	*init_builds(void);
int			hash_search(const char *key, t_builtin *builds);
t_bool		valid_hash(int build_inx, int lst_size);

// tokenizer.c
t_type		*tokenizer(char *usr_in, t_shell *s_shell);

// parsing.c
void		parsing(char *std_in, t_shell *st_shell);
char		*find_var_assignment(char *str);

// expansion.c
void		find_var_and_expand(char **usr_in, t_bool is_assignment);

// parsing_utils.c
void		quit_quote(char *str, size_t *inx);
t_bool		is_word_start(char *str, size_t index);
t_bool		is_within_quotes(char *str, size_t index);
char		*remove_quotes_from_word(char *str, size_t word_end);

// var_utils.c
t_bool		is_valid_varname(char *str);
t_bool		is_valid_varname_char(char c);
char		*get_var_name(char *str);
t_var		*get_var_from_assignment(char *str);

#endif
