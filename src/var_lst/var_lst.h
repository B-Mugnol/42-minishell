/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_lst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:32:27 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/09/21 22:27:18 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_LST_H
# define VAR_LST_H

# include <stdlib.h>	// free, malloc
# include "libft.h"		// ft_strncmp, ft_strlen

typedef struct s_var
{
	char			*name;
	char			*value;
	struct s_var	*next;
}	t_var;

// lst_add.c
t_var	*var_lst_new(char *name, char *value);
void	var_lst_add_back(t_var **lst, t_var *new);
void	var_lst_add_front(t_var **lst, t_var *new);
void	var_lst_add_var(t_var **lst, t_var *new);

// lst_del.c
void	var_lst_clear(t_var **lst);
void	var_lst_delete_node(t_var *node);
void	var_lst_delete_var(t_var **lst, char *name);

// lst_get.c
size_t	var_lst_size(t_var *lst);
t_var	*var_lst_find_var(char *name, t_var *lst);

#endif
