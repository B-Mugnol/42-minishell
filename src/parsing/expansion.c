/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:20:52 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/12 19:21:21 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

char	*expand_tilde(char *str, char *tilde_pointer)
{
	char	*exp;

	exp = ft_strmerge(ft_substr(str, 0, tilde_pointer - str),
			ft_strdup(getenv("HOME")));
	exp = ft_strmerge(exp, ft_strdup(tilde_pointer + 1));
	return (exp);
}

char	*expand_var(char *str, char *exp_start, char *var_name, t_var *var_lst)
{
	t_var	*var;
	char	*var_value;
	char	*exp;

	var_value = NULL;
	var = varlst_find_var(var_name, var_lst);
	if (var)
		var_value = ft_strdup(var->value);
	if (var_value == NULL)
		var_value = ft_strdup("");
	exp = ft_strmerge(ft_substr(str, 0, exp_start - str), var_value);
	exp = ft_strmerge(exp, ft_strdup(exp_start + ft_strlen(var_name) + 1));
	return (exp);
}

void	expand_usr_in(char	**usr_in, t_var *var_lst)
{
	char	*var_name;
	char	*aux;
	size_t	inx;

	inx = 0;
	while ((*usr_in)[inx])
	{
		if ((*usr_in)[inx] == '\'')
			quit_quote(*usr_in + inx, &inx);
		if ((*usr_in)[inx] == '$')
		{
			var_name = get_var_name(*usr_in + inx + 1);
			aux = expand_var(*usr_in, *usr_in + inx, var_name, var_lst);
			free(*usr_in);
			free(var_name);
			*usr_in = aux;
		}
		else
			inx++;
	}
}
