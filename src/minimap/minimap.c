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

void	write_pixel_data(t_img *img, int pixel, int color)
{
	if (img->endian == 1)
	{
		img->addr[pixel + 0] = (color >> 24);
		img->addr[pixel + 1] = (color >> 16) & 0xFF;
		img->addr[pixel + 2] = (color >> 8) & 0xFF;
		img->addr[pixel + 3] = (color) & 0xFF;
	}
	else if (img->endian == 0)
	{
		img->addr[pixel + 0] = (color) & 0xFF;
		img->addr[pixel + 1] = (color >> 8) & 0xFF;
		img->addr[pixel + 2] = (color >> 16) & 0xFF;
		img->addr[pixel + 3] = (color >> 24);
	}
}

void	create_image(t_img *image, t_data *d, int resolution[2], int casecolor)
{
	int		color;
	int		x;
	int		y;
	int		pixel;

	x = 0;
	y = 0;
	color = casecolor;
	image->img = mlx_new_image(d->mlx_ptr, resolution[1], resolution[0]);
	image->addr = (int *)mlx_get_data_addr(image->img, \
		&image->bpp, &image->sl, &image->endian);
	if (image->bpp != 32)
		color = mlx_get_color_value(d->mlx_ptr, color);
	while (y < resolution[0])
	{
		while (x < resolution[1])
		{
			pixel = (y * image->sl) + (x * 4);
			write_pixel_data(image, pixel, color);
			x++;
		}
		x = 0;
		y++;
	}
}

static void	choose_texture(t_data *d, int i, int j)
{
	if (d->map_arr[i][j] == '1')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->wall.img, \
			j * 15, i * 15);
	if (d->map_arr[i][j] == '0')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->path.img, \
			j * 15, i * 15);
}

void	draw_map(t_data *data)
{
	int	j;
	int	i;
    int resolution[2] = {20, 20};

    i = 0;
	j = 0;
	create_image(&data->wall, data, resolution, 0xFF0000);
    create_image(&data->path, data, resolution, 0x00FFFF);
    while (data->map_arr[i])
	{
		while (data->map_arr[i][j])
			choose_texture(data, i, j++);
		j = 0;
        i++;
	}
	mlx_destroy_image(data->mlx_ptr, data->wall.img);
	mlx_destroy_image(data->mlx_ptr, data->path.img);
}
