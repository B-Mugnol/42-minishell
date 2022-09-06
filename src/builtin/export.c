/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:23:34 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/26 01:42:24 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static t_var	*get_export_var(char *export_str);
static char		**get_export_words(char *export_str);
static void		update_environment(t_var *export);
static void		invalid_name_error(char *var_name);

void	ft_export(char *usr_in)
{
	t_var	*vars;

	vars = get_export_var(usr_in);
	if (!vars)
	{
		// export sem argumentos
	}
	update_environment(vars);
}

static t_var	*get_export_var(char *export_str)
{
	char	**words;
	size_t	inx;
	t_var	*export_vars_lst;
	t_var	*new_var;

	words = get_export_words(export_str);
	if (!words)
		return (NULL);
	export_vars_lst = NULL;
	inx = 1;
	while (words[inx])
	{
		if (!is_valid_varname(words[inx]))
			invalid_name_error(words[inx]);
		else
		{
			new_var = get_var_from_assignment(words[inx]);
			var_lst_add_front(&export_vars_lst, new_var);
		}
		inx++;
	}
	ft_free_char_matrix(&words);
	return (export_vars_lst);
}

static char	**get_export_words(char *export_str)
{
	char	**words;


	if (!export_str || !*export_str
		|| export_str[ft_strlen(export_str) - 1] == '|')
		return (NULL);
	words = ft_word_split(export_str, ft_isspace);
	if (!words)
		return (NULL);
	if (ft_strncmp(words[0], "export", ft_strlen("export") + 1) != 0)
	{
		ft_free_char_matrix(&words);
		return (NULL);
	}
	return (words);
}

static void	update_environment(t_var *export)
{
	t_var	*var;

	while (export)
	{
		var = var_lst_find_var(export->name, *g_env);
		if (ft_strncmp(export->name, "?", ft_strlen("?")) == 0)
			;
		else if (export->value != NULL)
			var_lst_add_var(g_env, var_lst_new(ft_strdup(export->name),
					ft_strdup(export->value)));
		else if (var != NULL)
		{
			var_lst_add_var(g_env,
				var_lst_new(ft_strdup(var->name), ft_strdup(var->value)));
		}
		export = export->next;
	}
}

static void	invalid_name_error(char *var_name)
{
	set_exit_status(EXIT_FAILURE);
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(var_name, 2);
	ft_putstr_fd("': not a valid identifier", 2);
}
