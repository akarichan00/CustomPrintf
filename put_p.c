/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:34:53 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/19 13:12:10 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_p(unsigned long number, char *base)
{
	int				count;
	unsigned long	base_len;

	base_len = ft_strlen(base);
	count = 0;
	if (number == 0)
	{
		count += ft_putchar('0');
		return (count);
	}
	if (number < base_len)
		count += ft_putchar(base[number]);
	else
	{
		count += put_p((number / base_len), base);
		count += ft_putchar(base[number % base_len]);
	}
	return (count);
}
