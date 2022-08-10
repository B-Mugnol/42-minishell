/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:48:36 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/27 06:15:38 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_token(char *str, char token, char new_value);
t_parse	*create_content(char *str, size_t len, t_token type);
void	quit_quote(char *str, size_t *inx);

t_list	*tokenizer(char *usr_in)
{
	t_list	*lst;
	size_t	inx;

	lst = NULL;
	inx = 0;
	while (usr_in[inx])
	{
		if (usr_in[inx] == '\"' || usr_in[inx] == '\'')
			quit_quote(usr_in, &inx);
		if (usr_in[inx] == '|')
		{
			ft_lstadd_back(&lst,
				ft_lstnew(create_content(usr_in, inx + 1, WORD)));
			usr_in += inx + 1;
			inx = 0;
		}
		inx++;
	}
	ft_lstadd_back(&lst, ft_lstnew(create_content(usr_in, inx + 1, WORD)));
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

t_parse	*create_content(char *str, size_t len, t_token type)
{
	t_parse	*node;

	if (str == NULL || *str == '\0')
		return (NULL);
	node = malloc(sizeof(t_parse));
	node->str = ft_substr(str, 0, len);
	node->type = type;
	return (node);
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
