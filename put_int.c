/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:22:17 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/19 13:02:22 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_int(int n, char *base)
{
	int		count;
	int		base_len;
	long	number;

	number = (long)n;
	base_len = ft_strlen(base);
	count = 0;
	if (number < 0)
	{
		ft_putchar('-');
		number *= -1;
		count++;
	}
	if (number < base_len)
		count += ft_putchar(base[number]);
	else
	{
		count += put_int((number / base_len), base);
		count += ft_putchar(base[number % base_len]);
	}
	return (count);
}
