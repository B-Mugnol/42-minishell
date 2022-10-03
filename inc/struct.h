/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:31:25 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/03 21:58:58 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_builtin
{
	char	*name;
	void	(*func)();
}	t_builtin;

typedef enum e_error
{
	SUCCESS,
	NO_DIR,
	DENI_PERMI,
	IS_DIR
}	t_error;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_shell
{
	char		*cmd;
	char		**args;
	int			pipe[2];
	int			lst_inx;
	int			infile;
	int			outfile;
	int			lst_size;
	int			exit_status;
	char		*error_locale;
	t_error		file_stat;
}	t_shell;

#endif
