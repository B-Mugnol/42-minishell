/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:09:54 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/09/06 19:54:43 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "var_lst.h"
# include "type_lst.h"

// tokenizer.c
t_type	*tokenizer(char *usr_in, t_shell *s_shell);

// parsing.c
void	parsing(char *std_in, t_shell *st_shell);
char	*find_var_assignment(char *str);

// expansion.c
void	find_var_and_expand(char **usr_in, t_bool is_assignment);
char	*substitute(char *str, size_t sub_start, size_t sub_end, char *sub);

// parsing_utils.c
void	quit_quote(char *str, size_t *inx);
t_bool	is_word_start(char *str, size_t index);
t_bool	is_within_quotes(char *str, size_t index);
char	*remove_quotes_from_word(char *str, size_t word_end);

// var_utils.c
t_bool	is_valid_varname(char *str);
t_bool	is_valid_varname_char(char c);
char	*get_var_name(char *str);
t_var	*get_var_from_assignment(char *str);

#endif
