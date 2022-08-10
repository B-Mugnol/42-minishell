/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:48:36 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/11 00:35:17 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_token(char *str, char token, char new_value);
void	quit_quote(char *str, size_t *inx);

t_type	*tokenizer(char *usr_in)
{
	t_type	*lst;
	size_t	inx;

	lst = NULL;
	inx = 0;
	while (usr_in[inx])
	{
		if (usr_in[inx] == '\"' || usr_in[inx] == '\'')
			quit_quote(usr_in, &inx);
		if (usr_in[inx] == '|')
		{
			typelst_add_back(&lst,
				typelst_new(ft_substr(usr_in, 0, inx + 1), WORD));
			usr_in += inx + 1;
			inx = 0;
		}
		inx++;
	}
	typelst_add_back(&lst, typelst_new(ft_substr(usr_in, 0, inx + 1), WORD));
	return (lst);
}

void	quit_quote(char *str, size_t *inx)
{
	char	quote;

	quote = str[*inx];
	*inx = *inx + 1;
	while (str[*inx])
	{
		if (str[*inx] == quote)
			break ;
		*inx += 1;
	}
}

void	replace_token(char *str, char token, char new_value)
{
	size_t	s_quote_count;
	size_t	d_quote_count;

	if (!str)
		return ;
	s_quote_count = 0;
	d_quote_count = 0;
	while (*str)
	{
		if (*str == '\"' && s_quote_count % 2 == 0)
			d_quote_count++;
		if (*str == '\'' && d_quote_count % 2 == 0)
			s_quote_count++;
		if ((s_quote_count % 2 == 1 || d_quote_count % 2 == 1) && *str == token)
			*str = new_value;
		str++;
	}
}
