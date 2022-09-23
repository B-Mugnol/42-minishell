/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_lst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:06:46 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/22 21:02:38 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_LST_H
# define TYPE_LST_H

# include <stdlib.h>
# include "struct.h"

typedef struct s_type
{
	char			*str;
	struct s_type	*next;
}	t_type;

t_type	*type_lst_new(char *str_in);
void	type_lst_add_back(t_type **lst, t_type *new);
void	type_lst_add_front(t_type **lst, t_type *new);
void	type_lst_delete_node(t_type *node);
void	type_lst_clear(t_type **lst);
int		type_lst_size(t_type *lst);

#endif
