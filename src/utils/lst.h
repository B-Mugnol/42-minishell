/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:32:27 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/07/15 04:49:13 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

#include <stdlib.h>	// free, malloc
#include "libft.h"	// ft_strncmp, ft_strlen

typedef struct s_node
{
	char			*name;
	char			*value;
	struct s_node	*next;
}	t_node;

// lst_add.c
t_node	*lst_new(char *name, char *value);
void	lst_add_back(t_node **lst, t_node *new);
void	lst_add_front(t_node **lst, t_node *new);
void	lst_add_var(t_node **lst, t_node *new);
t_node	*find_var(char *name, t_node *lst);

// lst_del.c
void	lst_clear(t_node **lst);
void	lst_delete_node(t_node *node);
void	lst_delete_var(t_node **lst, char *name);


#endif
