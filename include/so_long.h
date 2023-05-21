/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:47:34 by juzheng           #+#    #+#             */
/*   Updated: 2023/05/10 14:47:35 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_img
{
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}		t_img;

typedef struct s_cnt
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}		t_cnt;

typedef struct s_pos
{
	int		x;
	int		y;
}		t_pos;	

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
	char	**map;
	t_cnt	content;
	t_img	img;
	t_pos	pos;
	int		count;
}		t_data;

void	*ft_error(char *str);

char	**map_core(char **str, t_data *data);

int		chk_collect(t_data *data);
void	ft_check_content(t_data *data);
int		ft_check_format(char **map);
int		ft_check_line(char *map_line, char wall);
int		ft_check_col(char *map_line, char wall, t_data *data);
int		ft_check_other(char *map_line, t_cnt *content);

void	set_img(t_data *data);
void	set_content(t_cnt *content);

void	core_render(t_data *data);
void	render_top(t_data *data);
void	render_right(t_data *data);
void	render_left(t_data *data);
void	render_down(t_data *data);
void	print_img(t_data *data, void *img, int x, int y);

int		key_press(int keysym, t_data *data);
int		end(t_data *data);
#endif
