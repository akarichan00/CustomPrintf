/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:02:07 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/16 11:21:58 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int check_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' 
	|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (0);
	return (1);
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
			s += 2;
			if (format == 'd')
			{
				// storing the argument in a variable 
				//to prevent calling va_arg twice aka using two arguments 
				int num = va_arg(args, int);
				ft_putnbr(va_arg(args, int));
				count += ft_putnbr(num);
			}
			else if (format == 's')
			{
				char *str = va_arg(args, char *);
				ft_putstr(va_arg(args, char *));
				count += ft_putstr(str);
			}
			else if(format == 'c')
			{
				ft_putchar(va_arg(args, char));
				count += 1;
			}
			else if(format == '%')
			{
				ft_putchar('%');
				count += 1;	
			}
		}
		else
		{
			ft_putchar(*s);
			s++;
		}
	}
	va_end(args);
	return (count);
}
int main()
{
	ft_printf("khtek %s", "zwina");
}