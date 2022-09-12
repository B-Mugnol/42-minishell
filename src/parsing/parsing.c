/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:34:17 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/06 21:06:55 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

void	cmd_recognizer(t_type *token_lst);
void	parsing_loop(t_type *token_lst, t_shell *st_shell);

void	parsing(char *std_in, t_shell *st_shell)
{
	t_type	*token_lst;

	token_lst = tokenizer(std_in, st_shell);
	parsing_loop(token_lst, st_shell);
	type_lst_clear(&token_lst);
}

void	parsing_loop(t_type *token_lst, t_shell *st_shell)
{
	while (token_lst)
	{
		find_var_and_expand(&token_lst->str, FALSE);
		if (builds(token_lst, st_shell) == FALSE)
			token_lst = token_lst->next;
		else
		{
			//reconhecer comandos
			//criar fork e executar e mandar a saida certa
			token_lst = token_lst->next;
		}
	}
}

char	*find_var_assignment(char *str)
{
	char	*start;
	size_t	inx;
	size_t	equal_inx;

	inx = 0;
	while (str[inx])
	{
		if (str[inx] == '\"' || str[inx] == '\'')
			quit_quote(str, &inx);
		if (str[inx] == '=')
		{
			equal_inx = inx;
			while (inx != 0 && ft_isspace(str[inx]))
				inx--;
			if (ft_isspace(str[inx]))
				inx++;
			start = str + inx;
			while (inx != equal_inx)
				if (!is_valid_varname_char(str[inx++]))
					return (NULL);
			return (start);
		}
		inx++;
	}
	return (NULL);
}
