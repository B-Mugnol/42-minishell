/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:43:21 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/09/22 23:37:25 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static t_bool	has_n_flag(char **words);

void	ft_echo(char *usr_in)
{
	char	**words;
	char	*unquoted;
	t_bool	n_flagged;
	size_t	inx;

	set_exit_status(EXIT_SUCCESS);
	words = ft_word_split(usr_in, ft_isspace);
	if (!words)
		return (set_exit_status(EXIT_FAILURE));
	n_flagged = has_n_flag(words);
	inx = 1;
	if (n_flagged)
		inx = 2;
	while (words[inx])
	{
		unquoted = remove_quotes_from_word(words[inx], ft_strlen(words[inx]));
		ft_putstr_fd(unquoted, 1);
		if (words[inx + 1])
			ft_putchar_fd(' ', 1);
		free(unquoted);
		inx++;
	}
	if (!n_flagged)
		ft_putchar_fd('\n', 1);
	ft_free_char_matrix(&words);
}

static t_bool	has_n_flag(char **words)
{
	char	*unquoted;
	t_bool	n_flagged;

	if (!words || !words[1])
		return (FALSE);
	unquoted = remove_quotes_from_word(words[1], ft_strlen(words[1]));
	if (strncmp(unquoted, "-n", 3) == 0)
		n_flagged = TRUE;
	else
		n_flagged = FALSE;
	free(unquoted);
	return (n_flagged);
}
