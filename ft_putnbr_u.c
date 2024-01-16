/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:41:17 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/16 20:49:22 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_putnbr_u(unsigned int n, char *base)
{
	unsigned  int	number;
	int count;
	unsigned  int base_len;

	base_len = 0;
	count = 0;
	number = n;
	while(base[base_len])
		base_len++;
    if (number >= base_len)
    {
        ft_putchar(base[number]);
        count++;
    }
	else
    {
        count += ft_putnbr((number / base_len), base);
        ft_putchar(base[number % base_len]);
        count++;
    }
	return (count);
}