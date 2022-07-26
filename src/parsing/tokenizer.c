/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:48:36 by llopes-n          #+#    #+#             */
/*   Updated: 2022/07/26 21:25:19 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenizer(char *usr_in)
{
	t_parse	*node;
	int		inx;

	inx = 0;
	while (usr_in[inx])
	{
		if (usr_in[inx] == '|')
		{
			usr_in += inx;
			inx = 0;
		}
		inx++;
	}
}
