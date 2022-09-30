/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:48:36 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/30 07:07:17 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

static t_bool	is_empty_str(char *usr_in);

t_type	*tokenizer(char *usr_in, t_shell *st_shell)
{
	t_type	*lst;
	size_t	inx;

	if (is_empty_str(usr_in))
		return (NULL);
	lst = NULL;
	inx = 0;
	while (usr_in[inx])
	{
		if (usr_in[inx] == '\"' || usr_in[inx] == '\'')
			quit_quote(usr_in, &inx);
		if (usr_in[inx] == '|')
		{
			type_lst_add_back(&lst,
				type_lst_new(ft_substr(usr_in, 0, inx)));
			usr_in += inx + 1;
			inx = 0;
		}
		inx++;
	}
	type_lst_add_back(&lst, type_lst_new(ft_substr(usr_in, 0, inx)));
	st_shell->lst_size = type_lst_size(lst);
	return (lst);
}

static t_bool	is_empty_str(char *usr_in)
{
	char	*aux;

	aux = ft_strtrim(usr_in, WHITE_SPACE_CHARS);
	if (!aux)
		return (TRUE);
	if (!*aux)
	{
		free(aux);
		return (TRUE);
	}
	free(aux);
	return (FALSE);
}
