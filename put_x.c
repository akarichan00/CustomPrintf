/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:35:31 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/19 13:10:05 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_x(unsigned int number, char *base)
{
	int				count;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	count = 0;
	if (number < base_len)
		count += ft_putchar(base[number]);
	else
	{
		count += put_x((number / base_len), base);
		count += ft_putchar(base[number % base_len]);
	}
	return (count);
}
