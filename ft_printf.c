/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:02:07 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/16 20:58:54 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int check_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' 
	|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int ft_printf(const char *s, ...)
{
	va_list args;
	int count;

	count = 0;
	va_start(args, s);
	while(*s)
	{
		if (*s == '%' && check_format(*(s + 1)))
		{
			char format = *(s + 1);
			// incrementing the string pointer by 2 cuz we use "%s" or "%d" ... which consume two characters
			if (format == 'd' || format == 'i')
			{
				// storing the argument in a variable 
				//to prevent calling va_arg twice aka using two arguments 
				int num = va_arg(args, int);
				count += ft_putnbr(num, "0123456789");
				s += 2;
			}
		//debug this
			// else if (format == 'p')
			// {
			// 	void *ptr = va_arg(args, void *);
			// 	if (ptr)
			// 	{
			// 		count +=write(1, "0x", 2);
			// 		count += ft_putnbr((unsigned long)ptr, "0123456789abcdef");
			// 	}
			// 	else
			// 		ft_putstr("0x0");
			// 	s += 2;
			// }
			else if (format == 'u')
			{
				// doesnt hadnle negative values
				unsigned int num = va_arg(args, unsigned int);
				count += ft_putnbr(num, "0123456789");
				s += 2;
			}
			else if (format == 's')
			{
				char *str = va_arg(args, char *);
				count += ft_putstr(str);
				s += 2;
			}
			else if(format == 'c')
			{
				ft_putchar(va_arg(args, int));
				count += 1;
				s += 2;
			}
			else if(format == '%')
			{
				ft_putchar('%');
				count += 1;	
				s += 2;
			}
		}
		else
		{
			ft_putchar(*s);
			count++;
			s++;
		}
	}
	va_end(args);
	return (count);
}
#include <stdio.h>

int main()
{
	// int a = ft_printf("character: %c\n",'x');
	// printf("%d\n", a);
	// int b = printf("character: %i\n", 0xffffffff);
	// if ()
	// printf("%d\n", b);
	// int a = 5;
	printf("%u\n",  1);
	ft_printf("%u\n",  1);

	
}

// format checked : %d %i %c %s %%