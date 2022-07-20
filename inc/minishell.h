/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:40:30 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/19 22:52:21 by llopes-n         ###   ########.fr       */
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
# include "lst.h"

typedef struct s_buildin
{
	char	*name;
	void	(*func)(void *);
}	t_buildin;

typedef struct s_glo
{
	char	*cmd;
	char	**args;
}	t_glo;

typedef enum e_bool
{
	TRUE,
	FALSE
}	t_bool;

void	get_comman(char *usr_in, t_node *env_lst, t_glo *comman);
t_node	*set_node(void);
t_bool	hash_search(const char *key, t_node *env);

// builtins.c
void	ft_env(t_node *env_lst);
void	ft_pwd(void);

#endif
