/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:10:17 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/07 18:44:09 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*format_handler(const char *format, va_list ap, int *i);
static const char	*exception_handler(const char *format, va_list ap, int *i);
static char			*p_handler(va_list ap);
static int			is_printf_flag(char c);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		char_count;

	char_count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%' || *(format + 1) == '\0')
		{
			if (IS_MACOS && *format == '%')
				break ;
			ft_putchar_fd(*format, 1);
			char_count++;
			format++;
		}
		else
			format = format_handler(format + 1, ap, &char_count);
	}
	va_end(ap);
	return (char_count);
}

static const char	*format_handler(const char *format, va_list ap, int *i)
{
	char	*s;

	s = NULL;
	if (*format == 's')
		s = va_arg(ap, char *);
	else if (*format == 'p')
		s = p_handler(ap);
	else if (*format == 'd' || *format == 'i')
		s = ft_itoa(va_arg(ap, int));
	else if (*format == 'u')
		s = ft_utoa(va_arg(ap, unsigned int));
	else if (*format == 'x')
		s = ft_xtoa(va_arg(ap, unsigned int));
	else if (*format == 'X')
		s = ft_xto_uppercase_a(va_arg(ap, unsigned int));
	else
		return (exception_handler(format, ap, i));
	ft_putstr_fd(s, 1);
	if (s)
		*i += (int)(ft_strlen(s));
	else if (*format != '%' && *format != 'c')
		*i += 6;
	if (s && *format != 's')
		ft_null_free((void *)(s));
	return (format + 1);
}

static char	*p_handler(va_list ap)
{
	char	*s;

	s = ft_ptoa(va_arg(ap, void *));
	if (!s)
	{
		if (IS_MACOS)
			s = ft_strdup("0x0");
		else
			s = ft_strdup("(nil)");
	}
	return (s);
}

static const char	*exception_handler(const char *format, va_list ap, int *i)
{
	if (*format == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (*format == '%' || (is_printf_flag(*format) && !IS_MACOS))
		ft_putchar_fd('%', 1);
	else if (IS_MACOS && (is_printf_flag(*format) || *format == '\0'))
		i -= 1;
	else if (IS_MACOS && !is_printf_flag(*format))
		ft_putchar_fd(*format, 1);
	else
		ft_putchar_fd(*(--format), 1);
	*i += 1;
	return (format + 1);
}

static int	is_printf_flag(char c)
{
	if (ft_strchr(PRINTF_FLAGS, c))
		return (1);
	return (0);
}
