/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 04:36:29 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/02 20:03:15 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	*get_clean_line(int fd, char *old_input);

t_bool	has_here_doc(t_pipe *pipe_lst, t_shell *st_shell, size_t inx)
{
	char	*tk;

	if (inx >= ft_strlen(pipe_lst->str))
		return (FALSE);
	tk = ft_strnstr(pipe_lst->str + inx, "<<",
			ft_strlen(pipe_lst->str + inx));
	if (!tk)
		return (TRUE);
	inx = tk - pipe_lst->str;
	if (!is_within_quotes(pipe_lst->str, inx))
	{
		if (set_redirect(pipe_lst, st_shell, inx) == FALSE)
			return (FALSE);
		return (TRUE);
	}
	return (has_here_doc(pipe_lst, st_shell, inx + 1));
}

t_bool	here_doc(char *delimiter, t_shell *shell)
{
	char	*input;
	int		rw_pipe[2];

	pipe(rw_pipe);
	input = NULL;
	if (get_exit_status() == 130)
		set_exit_status(EXIT_SUCCESS);
	while (!input || ft_strncmp(input, delimiter, ft_strlen(input) + 1) != 0)
	{
		if (input)
			ft_putendl_fd(input, rw_pipe[1]);
		ft_putstr_fd("> ", STDOUT_FILENO);
		input = get_clean_line(STDIN_FILENO, input);
		if (!input && get_exit_status() == 130)
			return (FALSE);
		else if (!input)
		{
			ft_putstr_fd("\n", STDOUT_FILENO);
			break ;
		}
	}
	free(input);
	close(rw_pipe[1]);
	shell->infile = rw_pipe[0];
	return (TRUE);
}

static char	*get_clean_line(int fd, char *old_input)
{
	char	*temp;
	char	*aux;

	free(old_input);
	temp = get_next_line(fd);
	if (!temp)
		return (NULL);
	if (*temp == 1)
	{
		free(temp);
		return (NULL);
	}
	aux = ft_substr(temp, 0, ft_strlen(temp) - 1);
	free(temp);
	find_var_and_expand(&aux, FALSE);
	return (aux);
}
