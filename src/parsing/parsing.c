/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:34:17 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/26 01:38:19 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

void	cmd_recognizer(t_type *token_lst);

void	parsing(char *std_in)
{
	t_type	*token_lst;

	token_lst = tokenizer(std_in);
	cmd_recognizer(token_lst);
	type_lst_clear(&token_lst);
}

void	cmd_recognizer(t_type *token_lst)
{
	find_var_and_expand(&token_lst->str, FALSE);
}

char	*recognize_builds(t_type *token_lst)
{
	char		**words;
	char		*build;
	int			inx;
	t_builtin	*builds;

	inx = 0;
	words = ft_word_split(token_lst->str, ft_isspace);
	builds = init_builds();
	if (!words)
		return (NULL);
	while (words[inx])
	{
		if (token_lst->next == NULL)
			build = hash_search(words[inx], builds);
		else
			build = search_valid_hash(words[inx]);
		if (build)
			return (build);
		inx++;
	}
	return (NULL);
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
