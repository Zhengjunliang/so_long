# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juzheng <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 16:40:45 by juzheng           #+#    #+#              #
#    Updated: 2022/11/27 16:40:46 by juzheng          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror 
RM		=	rm -f

SRCS	=	ft_printf.c ft_printf_utils.c \
			ft_put_unsigned.c \
			ft_digits_hexa.c ft_digits.c \

OBJS	=	$(SRCS:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
			ar	rcs	$(NAME)	$(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM)	$(NAME)

re: fclean $(NAME)

.PHONY:		all clean fclean re