/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:48:36 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/06 19:56:26 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

t_type	*tokenizer(char *usr_in, t_shell *st_shell)
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
			type_lst_add_back(&lst,
				type_lst_new(ft_substr(usr_in, 0, inx + 1), WORD));
			usr_in += inx + 1;
			inx = 0;
		}
		inx++;
	}
	type_lst_add_back(&lst, type_lst_new(ft_substr(usr_in, 0, inx + 1), WORD));
	st_shell->lst_size = type_lst_size(lst);
	return (lst);
}
