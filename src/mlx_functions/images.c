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

void	load_textures(t_data *data)
{
	data->tex[0].img = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->no_path, &data->tex[0].width, &data->tex[0].height);
	data->tex[1].img = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->so_path, &data->tex[1].width, &data->tex[1].height);
	data->tex[2].img = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->we_path, &data->tex[2].width, &data->tex[2].height);
	data->tex[3].img = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->ea_path, &data->tex[3].width, &data->tex[3].height);
}

void	get_data_addr(t_data *data)
{
	data->tex[0].addr = mlx_get_data_addr(data->tex[0].img, \
		&data->tex[0].bpp, &data->tex[0].line_length, &data->tex[0].endian);
	data->tex[1].addr = mlx_get_data_addr(data->tex[1].img, \
		&data->tex[1].bpp, &data->tex[1].line_length, &data->tex[1].endian);
	data->tex[2].addr = mlx_get_data_addr(data->tex[2].img, \
		&data->tex[2].bpp, &data->tex[2].line_length, &data->tex[2].endian);
	data->tex[3].addr = mlx_get_data_addr(data->tex[3].img, \
		&data->tex[3].bpp, &data->tex[3].line_length, &data->tex[3].endian);
}
