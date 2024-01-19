/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:02:07 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/19 11:13:07 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' 
	|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
#include <stdio.h>
int do_the_thing(va_list args, char format)
{
	int count;

	count = 0;
	if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int), "0123456789");
	else if (format == 'u')
		count += ft_putnbr(va_arg(args, unsigned int), "0123456789");
	else if (format == 'x')
		count += ft_putnbr(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		count += ft_putnbr(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == 'p')
	{
		void *ptr = va_arg(args, void *);
		if (ptr)
		{
			count +=ft_putstr("0x");
			count += ft_putnbr((long)ptr, "0123456789abcdef");
		}
		else
			count += ft_putstr("0x0");
	}
	else if (format == 's')
	{
		count += ft_putstr(va_arg(args, char *));
	}
		
	else if(format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if(format == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(format);
	return count;
}

int ft_printf(const char *s, ...)
{
	
	va_list args;
	int count;
	
	count  = 0;
	va_start(args, s);
	while(*s)
	{
		if (*s == '%' &&  check_format(*(s + 1)) && *(s + 1) != '\0')
		{
			count += do_the_thing(args, *(s + 1));
			s += 2;
		}
		else
		{
			count += ft_putchar(*s);
			s++;
		}
	}
	va_end(args);
	return (count);
}


// format checked : %d %i %c %s %% %p 