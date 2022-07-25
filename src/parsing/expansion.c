/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:20:52 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/07/25 22:37:31 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_tilde(char *str, char *tilde_pointer)
{
	char	*exp;

	exp = ft_strmerge(ft_substr(str, 0, tilde_pointer - str),
			ft_strdup(getenv("HOME")));
	exp = ft_strmerge(exp, ft_strdup(tilde_pointer + 1));
	return (exp);
}

char	*expand_var(char *str, char *exp_start, char *var_name, t_var*var_lst)
{
	t_var	*var;
	char	*var_value;
	char	*exp;

	var_value = NULL;
	var = find_var(var_name, var_lst);
	if (var)
		var_value = ft_strdup(var->value);
	if (var_value == NULL)
		var_value = ft_strdup("");
	exp = ft_strmerge(ft_substr(str, 0, exp_start - str), var_value);
	exp = ft_strmerge(exp, ft_strdup(exp_start + ft_strlen(var_name)) + 1);
	return (exp);
}
