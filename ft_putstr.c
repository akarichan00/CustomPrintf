/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:34:11 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/17 12:02:05 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_putstr(char *str)
{
	int count;
	
	count = 0;
	while(str[count])
	{
		ft_putchar(str[count]);
		count++;	
	}
	return (count);
}