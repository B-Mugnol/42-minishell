/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:49:44 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/01 01:03:18 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_pwd(int write_fd)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putendl_fd(path, write_fd);
	free(path);
	set_exit_status(EXIT_SUCCESS);
}
