# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 13:02:29 by noben-ai          #+#    #+#              #
#    Updated: 2024/01/11 13:06:56 by noben-ai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -f

NAME =  libftprintf.a

SRCS	= ft_printf.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME) 

$(NAME):	$(OBJS)
	ar rcs $@ $^


%.o : %.c  ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all 