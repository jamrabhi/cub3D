/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:11:10 by dsy               #+#    #+#             */
/*   Updated: 2020/07/08 01:22:37 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	esc_window(int key, void *params)
{
	t_data	*data;

	(void)key;
	data = (t_data *)params;
	if (data->mlx_ptr != NULL && data->win_ptr != NULL)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("Exit (esc).\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int	cross_window(int key, void *params)
{
	(void)key;
	(void)params;
	printf("Exit (cross).\n");
	exit(EXIT_SUCCESS);
}

void	draw_gun(t_data *data)
{
	int		gun_size;
	t_img	img;

	gun_size = 1200;
	img.img = mlx_xpm_file_to_image(data->mlx_ptr, \
		"gun.xpm", &gun_size, &gun_size);
	img.addr = (int *)mlx_get_data_addr(img.img, \
		&img.bpp, &img.sl, &img.endian);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		img.img, SCREENSIZE - gun_size - 300, SCREENSIZE - gun_size);
	mlx_destroy_image(data->mlx_ptr, img.img);
}

// static void	toggle_minimap(t_data *data)
// {
// 	if (data->minimap == 0)
// 		data->minimap = 1;
// 	else
// 		data->minimap = 0;
// }

int	key_stroke(int key, void *params)
{
	t_data	*data;

	data = (t_data *)params;
	if (key == KEY_UP || key == KEY_UP_LINUX || \
		key == KEY_W || key == KEY_W_LINUX)
		data->move_up = 1;
	if (key == KEY_DOWN || key == KEY_DOWN_LINUX || \
		key == KEY_S || key == KEY_S_LINUX)
		data->move_down = 1;
	if (key == KEY_LEFT || key == KEY_LEFT_LINUX || \
		key == KEY_A || key == KEY_A_LINUX)
		data->turn_left = 1;
	if (key == KEY_RIGHT || key == KEY_RIGHT_LINUX || \
		key == KEY_D || key == KEY_D_LINUX)
		data->turn_right = 1;
	if (key == KEY_ESC || key == KEY_ESC_LINUX)
		esc_window(key, data);
	// if (key == KEY_M || key == KEY_M_LINUX)
	// 	toggle_minimap(data);
	draw_walls(data);
	// draw_gun(data);
	// if (data->minimap == 1)
	// 	draw_map(data);
	return (0);
}
