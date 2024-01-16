/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:02:14 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/16 20:46:52 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int ft_putnbr(int n, char *base);
int ft_putstr(char *str);
void ft_putchar(char c);
int ft_printf(const char *s, ...);
int ft_putnbr_u(unsigned int n, char *base);
#endif