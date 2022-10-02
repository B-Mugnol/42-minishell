/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_lst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:06:46 by llopes-n          #+#    #+#             */
/*   Updated: 2022/10/02 20:36:25 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_LST_H
# define PIPE_LST_H

# include <stdlib.h>
# include "struct.h"

typedef struct s_pipe
{
	char			*str;
	struct s_pipe	*next;
}	t_pipe;

t_pipe	*pipe_lst_new(char *str_in);
void	pipe_lst_add_back(t_pipe **lst, t_pipe *new);
void	pipe_lst_add_front(t_pipe **lst, t_pipe *new);
void	pipe_lst_delete_node(t_pipe *node);
void	pipe_lst_clear(t_pipe **lst);
int		pipe_lst_size(t_pipe *lst);

#endif
