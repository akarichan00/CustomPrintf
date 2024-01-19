# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 13:02:29 by noben-ai          #+#    #+#              #
#    Updated: 2024/01/19 11:16:37 by noben-ai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -f

NAME =  libftprintf.a

SRCS	= ft_printf.c ft_putnbr.c ft_putstr.c 

OBJS	= $(SRCS:.c=.o)

all:	$(NAME) 

$(NAME):	$(OBJS)
	ar rcs $@ $^


%.o : %.c  printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all 