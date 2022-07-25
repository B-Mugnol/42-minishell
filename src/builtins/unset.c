/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:49:46 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/07/25 19:51:18 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_node **var_lst, t_node **env_lst, char *var_name)
{
	if (!var_name || !*var_name)
		return ;
	lst_delete_var(var_lst, var_name);
	lst_delete_var(env_lst, var_name);
}
