/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:40:30 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/22 19:29:04 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
/*READLINE--GETENV*/
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <termios.h>	// getattr, setattr...
# include "libft.h"
# include "lst.h"

typedef struct s_buildin
{
	char	*name;
	void	(*func)();
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
void	ft_unset(t_node **var_lst, t_node **env_lst, char *var_name);

// signal.c
void	sig_setup(void);

#endif
