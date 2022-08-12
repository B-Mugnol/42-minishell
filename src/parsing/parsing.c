/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:34:17 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/12 02:45:11 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_recognizer(t_type *token_lst, t_var *var_lst);

void	parsing(char *std_in, t_var *var_lst)
{
	t_type	*token_lst;

	token_lst = tokenizer(std_in);
	cmd_recognizer(token_lst, var_lst);
	typelst_clear(&token_lst);
}

void	cmd_recognizer(t_type *token_lst, t_var *var_lst)
{
	expand_usr_in(&token_lst->str, var_lst);
}
