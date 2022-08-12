/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varlst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:32:27 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/12 19:58:42 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARLST_H
# define VARLST_H

# include <stdlib.h>	// free, malloc
# include "libft.h"		// ft_strncmp, ft_strlen

typedef struct s_var
{
	char			*name;
	char			*value;
	struct s_var	*next;
}	t_var;

// lst_add.c
t_var	*varlst_new(char *name, char *value);
void	varlst_add_back(t_var **lst, t_var *new);
void	varlst_add_front(t_var **lst, t_var *new);
void	varlst_add_var(t_var **lst, t_var *new);
t_var	*varlst_find_var(char *name, t_var *lst);

// lst_del.c
void	varlst_clear(t_var **lst);
void	varlst_delete_node(t_var *node);
void	varlst_delete_var(t_var **lst, char *name);

#endif
