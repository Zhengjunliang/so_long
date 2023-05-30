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

CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror -g 

LIBFT		= libft/libft.a

PRINTF_LBT	= ft_printf/libftprintf.a

SRCS_DIR	=	./src/

SRCS_F		=	so_long.c utils.c setup.c \
				map.c map_checker.c render.c \
				render_move.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_F))

OBJS		=	$(SRCS:.c=.o)

RM			=	rm -f

.c.o:
	$(CC) $(CCFLAGS) -Iminilibx-linux -c $< -o $(<:.c=.o) -I includes/

$(NAME):	$(OBJS)
	make -sC minilibx-linux
	make -sC libft
	make -sC ft_printf
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT) $(PRINTF_LBT) -L minilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME)

all:	$(NAME)

clean:
	make -sC ./minilibx-linux clean
	make -sC ./libft clean 
	make -sC ./ft_printf clean
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME) $(LIBFT) $(PRINTF_LBT)

re:			fclean all

.PHONY:		all clean fclean re