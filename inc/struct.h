/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:31:25 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/12 19:32:01 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_builtin
{
	char	*name;
	void	(*func)();
}	t_builtin;

typedef struct s_glo
{
	char	*cmd;
	char	**args;
	int		pipe[2];
}	t_glo;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

#endif
