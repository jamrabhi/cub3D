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

int	check_resolution(int x, int y)
{
	int	res;

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

void	draw_player(t_data *data, int px, int py)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (data->player.img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->player.img);
	data->player.img = mlx_new_image(data->mlx_ptr, 10, 10);
	data->player.addr = (int *)mlx_get_data_addr(data->player.img, \
		&data->player.bpp, &data->player.sl, &data->player.endian);
	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			*(data->player.addr + y * (data->player.sl / 4) + x) = 0x000000;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, \
		data->win_ptr, data->player.img, px, py);
	data->pos_x = px;
	data->pos_y = py;
}

void	draw_background(t_data *data, int top_color, int bottom_color)
{
	t_img	img;
	int		x;
	int		y;

	img.img = mlx_new_image(data->mlx_ptr, data->resolution, data->resolution);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bpp, \
		&img.sl, &img.endian);
	y = -1;
	while (++y < data->resolution)
	{
		x = -1;
		while (++x < data->resolution)
		{
			if (y < data->resolution / 2)
				*(img.addr + y * (img.sl / 4) + x) = top_color;
			else
				*(img.addr + y * (img.sl / 4) + x) = bottom_color;
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, img.img);
}
