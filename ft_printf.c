/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:02:07 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/20 18:15:18 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	handle_format(va_list args, char format)
{
	int	count;

	count = 0;
	if (format == 'd' || format == 'i')
		count += put_int(va_arg(args, int), "0123456789");
	else if (format == 'u')
		count += put_x(va_arg(args, unsigned int), "0123456789");
	else if (format == 'x')
		count += put_x(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		count += put_x(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == 'p')
	{
		count += put_str("0x");
		count += put_p((unsigned long)va_arg(args, void *), "0123456789abcdef");
	}
	else if (format == 's')
		count += put_str(va_arg(args, char *));
	else if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(format);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1) == '\0')
			return (count);
		if (*s == '%' && *(s + 1) != '\0')
		{
			s++;
			if (check_format(*s))
				count += handle_format(args, *s);
			else 
				count += ft_putchar(*s);
			s++;
		}
		else
			count += ft_putchar(*s++);
	}
	va_end(args);
	return (count);
}
