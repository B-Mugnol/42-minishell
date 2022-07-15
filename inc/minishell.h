/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:40:30 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/15 03:36:49 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
/*READLINE--GETENV*/
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include <fcntl.h>

typedef struct s_glo
{
	char	*cmd;
	char	**args;
}	t_glo;

typedef struct s_node
{
	char			*name;
	char			*value;
	struct s_node	*next;
}	t_node;

typedef enum e_bool
{
	TRUE,
	FALSE
}	t_bool;

t_node	*shlst_new(char *name, char *value);
void	shlst_addback(t_node **lst, t_node *new);
t_node	*set_node(void);
t_node	*find_env(char *name, t_node *env_lst);
char	*get_comman(char *comman, t_node *env_lst);
#endif
