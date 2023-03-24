/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:05:23 by dsy               #+#    #+#             */
/*   Updated: 2020/07/08 01:22:50 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_square(int *img_addr, int resolution, int x, int y, int size, int color)
{
	int i;
	int j;
	int pixel;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			pixel = ((y + i) * (resolution) + (x + j));
			*(img_addr + pixel) = color;
		}
	}
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;
    int resolution[2] = {5, 5};
    int map_width_px = data->map_width * resolution[0];
    int map_height_px = data->map_height * resolution[1];
    t_img	img;

	img.img = mlx_new_image(data->mlx_ptr, map_width_px, map_height_px);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.sl, &img.endian);
	i = -1;
	while (data->map_arr[++i])
	{
		j = -1;
		while (data->map_arr[i][++j])
		{
			if (data->map_arr[i][j] == '1')
				draw_square(img.addr, map_width_px, j * resolution[0], i * resolution[1], resolution[0], 0xFF0000);
			else if (data->map_arr[i][j] == '0')
				draw_square(img.addr, map_width_px, j * resolution[0], i * resolution[1], resolution[0], 0x00FFFF);
			else if (data->map_arr[i][j] == data->spawn_dir)
				draw_square(img.addr, map_width_px, j * resolution[0], i * resolution[1], resolution[0], 0xFFFFFF);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, img.img);
}
