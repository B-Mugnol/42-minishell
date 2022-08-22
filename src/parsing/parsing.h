/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:09:54 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/22 16:24:19 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "var_lst.h"
# include "type_lst.h"

// tokenizer.c
t_type	*tokenizer(char *usr_in);

// parsing.c
void	parsing(char *std_in);
char	*find_var_assignment(char *str);

// expansion.c
void	expand_usr_in(char **usr_in);

// parsing_utils.c
void	quit_quote(char *str, size_t *inx);
void	replace_token(char *str, char token, char new_value);

// var_utils.c
t_bool	is_valid_varname(char *str);
t_bool	is_valid_varname_char(char c);

#endif
