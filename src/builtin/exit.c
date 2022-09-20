/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:34:05 by llopes-n          #+#    #+#             */
/*   Updated: 2022/09/20 23:06:50 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_digit_str(const char *str);
static int	exit_error(char *arg, char *err_msg);

void	ft_exit(char *usr_in)
{
	int		exit_status;
	char	**params;

	params = ft_word_split(usr_in, ft_isspace);
	if (!params)
		return (exit(EXIT_FAILURE));
	ft_putendl_fd("exit", 1);
	if (!params[1])
		exit_status = ft_atoi(var_lst_find_var("?", *g_env)->value);
	else if (!is_digit_str(params[1]))
	{
		exit_error(params[1], "numeric argument required");
		exit_status = BUILTIN_MISUSE_CODE;
	}
	else if (params[2])
	{
		ft_free_char_matrix(&params);
		return (set_exit_status(exit_error(NULL, "exit: too many arguments")));
	}
	else
		exit_status = ft_atoi(params[1]);
	ft_free_char_matrix(&params);
	rl_clear_history();
	var_lst_clear(g_env);
	return (exit(exit_status));
}

static int	is_digit_str(const char *str)
{
	if (!str || !*str || (*str != '-' && !ft_isdigit(*str)))
		return (0);
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	exit_error(char *arg, char *err_msg)
{
	char	*unquoted;

	ft_putstr_fd("exit: ", 2);
	if (!arg)
	{
		ft_putendl_fd(err_msg, 2);
		return (EXIT_FAILURE);
	}
	unquoted = remove_quotes_from_word(arg, ft_strlen(arg));
	ft_putstr_fd(unquoted, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err_msg, 2);
	free(unquoted);
	return (EXIT_FAILURE);
}
