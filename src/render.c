/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:52:39 by juzheng           #+#    #+#             */
/*   Updated: 2023/05/18 16:52:40 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == data->content.wall)
				print_img(data, data->img.img_wall, j, i);
			if (data->map[i][j] == data->content.space)
				print_img(data, data->img.img_floor, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}

void	render_other(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == data->content.collect)
				print_img(data, data->img.img_collect, j, i);
			if (data->map[i][j] == data->content.player)
			{
				data->pos.x = j * data->img.width;
				data->pos.y = i * data->img.height;
				print_img(data, data->img.img_player, j, i);
			}
			if (data->map[i][j] == data->content.exit)
				print_img(data, data->img.img_exit, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}

int	render(t_data *data)
{
	render_background(data);
	render_other(data);
	return (0);
}

void	core_render(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			(data->width * data->img.width),
			(data->height * data->img.height),
			"So_long");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_ptr);
		return ;
	}
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &key_press, data);
	mlx_hook(data->mlx_win, 17, 0, &end, data);
	mlx_loop(data->mlx_ptr);
	end(data);
}

void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		data->img.width * x, data->img.height * y);
}
