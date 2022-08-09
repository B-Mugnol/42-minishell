/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:49:46 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/08/09 20:17:31 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_var **var_lst, t_var **env_lst, char *var_name)
{
	if (!var_name || !*var_name)
		return ;
	varlst_delete_var(var_lst, var_name);
	varlst_delete_var(env_lst, var_name);
}
