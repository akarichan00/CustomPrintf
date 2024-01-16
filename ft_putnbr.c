/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:22:17 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/16 11:29:33 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_putnbr(int n)
{
	long int	number;
	int count;

	count = 0;
	number = n;
	if (number < 0)
	{
		ft_putchar('-');
		number *= -1;
	}
	if (number < 10)
	{
		ft_putchar(number + '0');
		count++;
	}
	else
	{
		ft_putnbr((number / 10));
		ft_putchar((number % 10) + '0');
	}
	return (count);
}

#include <stdio.h>
int main()
{
	printf("%d", ft_putnbr(123));
}