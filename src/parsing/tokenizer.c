/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:48:36 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/12 19:21:24 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

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
