# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juzheng <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 17:35:49 by juzheng           #+#    #+#              #
#    Updated: 2022/10/07 17:35:50 by juzheng          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isdigit.c ft_strncpy.c\
				ft_strlen.c \
				ft_strchr.c \
				ft_atoi.c ft_strdup.c ft_strjoin.c \
				ft_split.c ft_itoa.c ft_gnl.c\

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -I.

NAME		=	libft.a

all:	$(NAME)

$(NAME):	$(OBJS)
					ar rcs $(NAME) $(OBJS)

clean:				
					$(RM) $(OBJS) 

fclean:		clean
					$(RM) $(NAME)

re:					fclean $(NAME)


.PHONY:				all clean fclean re
