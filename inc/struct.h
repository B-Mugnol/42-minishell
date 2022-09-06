/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:31:25 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/09/06 19:34:20 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_builtin
{
	char	*name;
	void	(*func)();
}	t_builtin;

typedef struct s_shell
{
	char	*cmd;
	char	**args;
	int		pipe[2];
	int		lst_size;
}	t_shell;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

#endif
