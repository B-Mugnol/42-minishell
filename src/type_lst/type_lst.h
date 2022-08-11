/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_lst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:06:46 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/11 00:36:47 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_LST_H
# define TYPE_LST_H

typedef enum e_token
{
	PIPE = -1,
	LESS = -2,
	MORE = -3,
	DOLLAR = -4,
	PARAM = -5,
	CMD = -6,
	WORD = -7
}	t_token;

typedef struct s_type
{
	t_token			type;
	char			*str;
	struct s_type	*next;
}	t_type;

t_type	*typelst_new(char *str_in, t_token type);
void	typelst_add_back(t_type **lst, t_type *new);
void	typelst_add_front(t_type **lst, t_type *new);
void	typelst_delete_node(t_type *node);
void	typelst_clear(t_type **lst);
#endif