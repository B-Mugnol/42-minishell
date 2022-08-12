/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:19:06 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/12 02:50:09 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_valid_var_char(char c);
void	cmd_recognizer(t_type *token_lst, t_var *var_lst);

void	parsing(char *std_in, t_var *var_lst)
{
	t_type	*token_lst;

	token_lst = tokenizer(std_in);
	cmd_recognizer(token_lst, var_lst);
	// if (token_lst->next == NULL && token_lst->type == ATTR)
		// atribui
	typelst_clear(&token_lst);
}

void	cmd_recognizer(t_type *token_lst, t_var *var_lst)
{
	expand_usr_in(&token_lst->str, var_lst);
}

void	recognize_assignment(t_type *token_lst)
{
	size_t	inx;
	size_t	end_inx;
	char	*start;
	t_type	*sub_lst;

	inx = 0;
	sub_lst = NULL;
	while (token_lst->str[inx])
	{
		start = find_var_assignment(token_lst->str + inx);
		if (start == NULL)
			break ;
		end_inx = 0;
		while (start[end_inx] && !ft_isspace(start[end_inx]))
		{
			if (start[end_inx] == '\"' || start[end_inx] == '\'')
				quit_quote(start, &end_inx);
			end_inx++;
		}
		typelst_add_front(typelst_new(ft_substr(start, 0, end_inx)));
		inx = start - token_lst->str + end_inx;
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
				if (!is_valid_var_char(str[inx++]))
					return (NULL);
			return (start);
		}
		inx++;
	}
}

t_bool	is_valid_var_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (TRUE);
	return (FALSE);
}
