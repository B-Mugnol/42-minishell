/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:49:44 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/09/21 22:01:21 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putendl_fd(path, 1);
	free(path);
	set_exit_status(EXIT_SUCCESS);
}
