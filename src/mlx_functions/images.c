/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:43:27 by dsy               #+#    #+#             */
/*   Updated: 2020/07/08 01:23:06 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_player(t_data *data, int px, int py)
{
	if (data->player.img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->player.img);
	data->player.img = mlx_new_image(data->mlx_ptr, 10, 10);
	data->player.addr = (int *)mlx_get_data_addr(data->player.img, &data->player.bpp, &data->player.sl, &data->player.endian);
	int x =0, y = 0;
	y = 0;
	while (y < 10) {
		x = 0;
		while (x < 10) {
			*(data->player.addr + y * (data->player.sl / 4) + x) = 0x000000;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.img, px, py);
	data->pos_x = px;
	data->pos_y = py;
}

int check_resolution(int x, int y)
{
	int res;

	if (x > y)
		res = x;
	else
		res = y;
	if (res > 960)
		return (960);
	if (res < 320)
		return (320);
	return (res);
}

void draw_background(t_data *data, int top_color, int bottom_color) {
	int     width;
	int     height;
	int     half_height;
	int     x;
	int     y;
	t_img   bottom_img;
	t_img   top_img;

	width = data->resolution;
	height = data->resolution;
	half_height = height / 2;
	top_img.img = mlx_new_image(data->mlx_ptr, width, half_height);
	top_img.addr = (int *)mlx_get_data_addr(top_img.img, &top_img.bpp, &top_img.sl, &top_img.endian);
	bottom_img.img = mlx_new_image(data->mlx_ptr, width, half_height);
	bottom_img.addr = (int *)mlx_get_data_addr(bottom_img.img, &bottom_img.bpp, &bottom_img.sl, &bottom_img.endian);
	y = 0;
	while (y < half_height) {
		x = 0;
		while (x < width) {
			*(top_img.addr + y * (top_img.sl / 4) + x) = top_color;
			x++;
		}
		y++;
	}
	y = 0;
	while (y < half_height) {
		x = 0;
		while (x < width) {
			*(bottom_img.addr + y * (bottom_img.sl / 4) + x) = bottom_color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, top_img.img, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, bottom_img.img, 0, data->resolution / 2);
}
