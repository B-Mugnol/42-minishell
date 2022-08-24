/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:34:17 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/24 08:10:06 by llopes-n         ###   ########.fr       */
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
	expand_usr_in(&token_lst->str);
}

int	recognize_builds(t_type *token_lst)
{
	char		**words;
	int			build_inx;
	int			inx;
	t_builtin	*builds;

	inx = 0;
	build_inx = 7;
	words = ft_word_split(token_lst->str, ft_isspace);
	builds = init_builds();
	if (!words)
		return (NULL);
	while (words[inx])
	{
		if (token_lst->next == NULL)
			build_inx = hash_search(words[inx], builds);
		else
			build_inx = search_valid_hash(words[inx], builds);
		if (build_inx != 7)
			return (build_inx);
		inx++;
	}
	return (build_inx);
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
