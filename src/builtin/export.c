/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:23:34 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/12 20:04:30 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_export(t_var **var_lst, t_var **env_lst, t_var *export)
{
	t_var	*var;

	while (export)
	{
		var = var_lst_find_var(export->name, *var_lst);
		if (ft_strncmp(export->name, "?", ft_strlen("?")) == 0)
			;
		else if (export->value != NULL)
		{
			var_lst_add_var(var_lst, var_lst_new(ft_strdup(export->name),
					ft_strdup(export->value)));
			var_lst_add_var(env_lst, var_lst_new(ft_strdup(export->name),
					ft_strdup(export->value)));
		}
		else if (var != NULL)
		{
			var_lst_add_var(env_lst,
				var_lst_new(ft_strdup(var->name), ft_strdup(var->value)));
		}
		export = export->next;
	}
}
