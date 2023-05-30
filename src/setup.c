/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:50:03 by juzheng           #+#    #+#             */
/*   Updated: 2023/05/14 16:50:03 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_content(t_data *data)
{
	data->content.exit = 'E';
	data->content.player = 'P';
	data->content.wall = '1';
	data->content.space = '0';
	data->content.collect = 'C';
	data->content.count_p = 0;
	data->content.count_e = 0;
	data->content.count_c = 0;
	data->e_vars.sign = 1;
	data->e_vars.x = 0;
	data->e_vars.sleep = 5;
	data->e_vars.sleep_for_move = 60;
	data->e_vars.path_to_move = 0;
}

void	set_img(t_data *data)
{
	data->img.height = 64;
	data->img.width = 64;
	data->img.floor = "./textures/floor.xpm";
	data->img.wall = "./textures/wall.xpm";
	data->img.collect = "./textures/collect.xpm";
	data->img.player = "./textures/front.xpm";
	data->img.exit = "./textures/exit.xpm";
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, data->img.floor,
			&(data->img.width), &(data->img.height));
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
			&(data->img.width), &(data->img.height));
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collect, &(data->img.width), &(data->img.height));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
			&(data->img.width), &(data->img.height));
}
