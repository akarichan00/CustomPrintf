/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:34:11 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/19 11:16:18 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
}
int ft_putstr(char *str)
{
	int count;
	
	count = 0;
	if(!str)
	{
		write(1, "(null)", 6);
		return 6;	
	}
	while(str[count])
		ft_putchar(str[count++]);	
	return (count);
}