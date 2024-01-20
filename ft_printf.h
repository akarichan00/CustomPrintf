/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:40:53 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/19 15:40:54 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	put_int(int n, char *base);
int	put_str(char *str);
int	ft_putchar(char c);
int	put_p(unsigned long number, char *base);
int	put_x(unsigned int number, char *base);
int	ft_strlen(char *str);
#endif