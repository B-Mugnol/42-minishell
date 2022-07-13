/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:48:45 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/05 21:06:25 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif

# include <stdarg.h>
# include "libft.h"

# define PRINTF_FLAGS	"aAcCdeEfFgGhiIjlLmnopqstuxXzZ# +-0123456789.\'"

int	ft_printf(const char *format, ...);

#endif
