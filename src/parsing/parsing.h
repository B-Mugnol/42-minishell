/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:09:54 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/03 11:20:37 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define SYNTAX_ERROR "syntax error near unexpected token "
# define EOF_ERROR "warning: here-document delimited by end-of-file (wanted `"
# define LULUSHELL_ERROR "luluShell: "
# define ERROR_FILE_DIR "No such file or directory"
# define ERROR_PERMI "Permission denied"

# define WHITE_SPACE_CHARS " \f\n\r\t\v"

# include "minishell.h"
# include <sys/wait.h>
# include "var_lst.h"
# include "pipe_lst.h"

typedef enum e_tokens
{
	INFILE,
	OUTFILE,
	APPEND,
	HEREDOC,
	NOT_REDIR
}	t_tokens;

// commands.c
t_bool		recognizer_cmd(t_pipe *pipe_lst, t_shell *st_shell);
void		fork_exec(t_shell *st_shell, t_pipe *pipe_lst);

// build_ins.c
t_bool		is_builds(t_pipe *pipe_lst, t_shell *st_shell);
t_builtin	*init_builds(void);
int			hash_search(const char *key, t_builtin *builds);

// parsing_parse.c
t_pipe		*pipe_parse(char *usr_in, t_shell *s_shell);
t_bool		is_empty_str(char *usr_in);

// parsing.c
void		parsing(char *std_in, t_shell *st_shell);
char		*find_var_assignment(char *str);

// expansion.c
void		find_var_and_expand(char **usr_in, t_bool is_assignment);

// parsing_utils.c
void		quit_quote(char *str, size_t *inx);
t_bool		is_word_start(char *str, size_t index);
t_bool		is_within_quotes(char *str, size_t index);
char		*remove_quotes_from_word(char *str, size_t word_end);

// var_utils.c
t_bool		is_valid_varname(char *str);
t_bool		is_valid_varname_char(char c);
char		*get_var_name(char *str);
t_var		*get_var_from_assignment(char *str);

// set_in_outs.c
void		set_in_out(t_shell *st_shell);
t_bool		set_redirect(t_pipe *pipe_lst, t_shell *st_shell, size_t inx);
int			recognize_redirect(t_pipe *tk_lst, t_shell *shell);
t_error		check_file_access(char **file, t_tokens token, t_shell *st_shell);

// redirect_utils.c
void		cut_str(t_pipe *pipe_lst, int start_inx, int end_inx);
t_tokens	get_token(char *str, size_t *inx);
t_bool		file_name(char *file, size_t *str_inx, t_tokens tk, t_shell *shell);

// heredoc.c
t_bool		here_doc(char *delimiter, t_shell *shell);

#endif
