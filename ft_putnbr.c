/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:22:17 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/17 13:15:27 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while(str[len])
        len++;
    return len;
}

int ft_putnbr(long number, char *base)
{
	int count;
	int base_len;

	base_len = ft_strlen(base);
	count = 0;
	if (number < 0)
	{
		ft_putchar('-');
		number *= -1;
		count++;
	}
    if (number < base_len)
    {
        ft_putchar(base[number]);
        count++;
    }
	else
    {
        ft_putnbr((number / base_len), base);
        ft_putchar(base[number % base_len]);
        count++;
    }
	return (count);
}
// #include <stdio.h>
// int main()
// {
// 	printf("Testing with base 10:\n");
//     ft_putnbr(123, "0123456789");
//     printf("\n");

//     // Test with base 2
//     printf("Testing with base 2:\n");
//     ft_putnbr(123, "01");
//     printf("\n");

//     // Test with base 16
//     printf("Testing with base 16 uppercase:\n");
//     ft_putnbr(123, "0123456789ABCDEF");
//     printf("\n");

// 	printf("Testing with base 16 lowercase:\n");
//     ft_putnbr(123, "0123456789abcdef");
//     printf("\n");
	
//     // Test with negative number
//     printf("Testing with negative number:\n");
//     ft_putnbr(-123, "0123456789");
//     printf("\n");
// }