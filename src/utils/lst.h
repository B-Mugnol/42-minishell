/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:32:27 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/09 20:11:39 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include <stdlib.h>	// free, malloc
# include "libft.h"		// ft_strncmp, ft_strlen

typedef struct s_parse
{
	t_token			type;
	char			*str;
}	t_parse;

typedef struct s_var
{
	char			*name;
	char			*value;
	struct s_var	*next;
}	t_var;

// lst_add.c
t_var	*lst_new(char *name, char *value);
void	lst_add_back(t_var **lst, t_var *new);
void	lst_add_front(t_var **lst, t_var *new);
void	lst_add_var(t_var **lst, t_var *new);
t_var	*find_var(char *name, t_var *lst);

// lst_del.c
void	lst_clear(t_var **lst);
void	lst_delete_node(t_var *node);
void	lst_delete_var(t_var **lst, char *name);
void	delete_parse(void *parsed_node);

#endif
