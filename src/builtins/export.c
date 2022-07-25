/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:49:41 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/07/25 19:50:44 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_node **var_lst, t_node **env_lst, t_node *export)
{
	t_node	*var;

	while (export)
	{
		var = find_var(export->name, *var_lst);
		if (ft_strncmp(export->name, "?", ft_strlen("?")) == 0)
			;
		else if (export->value != NULL)
		{
			lst_add_var(var_lst, lst_new(ft_strdup(export->name),
					ft_strdup(export->value)));
			lst_add_var(env_lst, lst_new(ft_strdup(export->name),
					ft_strdup(export->value)));
		}
		else if (var != NULL)
		{
			lst_add_var(env_lst,
				lst_new(ft_strdup(var->name), ft_strdup(var->value)));
		}
		export = export->next;
	}
}
