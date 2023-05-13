# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juzheng <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:48:11 by juzheng           #+#    #+#              #
#    Updated: 2023/05/10 14:48:12 by juzheng          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS_DIR	=	./src/

SRCS_F		=	so_long.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_F))

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror -g 

RM			=	rm -f

.c.o:
	$(CC) $(CCFLAGS) -Iminilibx-linux -c $< -o $(<:.c=.o) -I includes/

$(NAME):		$(OBJS)
	make -sC minilibx-linux
	$(CC) $(OBJS) $(CCFLAGS) -L minilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME)

all:	$(NAME)

clean:
	make -sC ./minilibx-linux clean
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re