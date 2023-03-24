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

static void	toggle_minimap(t_data *data)
{
	if (data->minimap == 0)
		data->minimap = 1;
	else
		data->minimap = 0;
}

int	key_stroke(int key, void *params)
{
	t_data	*data;

	data = (t_data *)params;
	draw_background(data, 0x0, 0x0);
	if (key == KEY_W || key == KEY_W_LINUX)
	{
		data->pos_y -= 1;
		data->pos_y += data->pos_dy;
		data->pos_x += data->pos_dx;
	}
	if (key == KEY_S || key == KEY_S_LINUX)
	{
		data->pos_y += 1;
		data->pos_y -= data->pos_dy;
		data->pos_x -= data->pos_dx;
	}
	if (key == KEY_A || key == KEY_A_LINUX)
	{
		data->pos_ang -= 0.1;
		if (data->pos_ang < 0)
			data->pos_ang += 2 * PI;
		data->pos_dx = 5 * cos(data->pos_ang);
		data->pos_dy = 5 * sin(data->pos_ang);
	}
	if (key == KEY_D || key == KEY_D_LINUX)
	{
		data->pos_ang += 0.1;
		if (data->pos_ang > 2 * PI)
			data->pos_ang -= 2 * PI;
		data->pos_dx = 5 * cos(data->pos_ang);
		data->pos_dy = 5 * sin(data->pos_ang);
	}
	if (key == KEY_UP || key == KEY_UP_LINUX)
	{
		if ((int)(data->pos_x / data->map_width) > 0 && (int)(data->pos_x / data->map_width) < data->map_width - 1)
		{
			if (data->map_arr[(int)(data->pos_x / data->map_width) - 1][(int)(data->pos_y / data->map_height) - 1] != '1')
				data->map_arr[(int)(data->pos_x / data->map_width) - 1][(int)(data->pos_y / data->map_height) - 1] = '0';
			data->pos_y -= 1;
			data->pos_y += data->pos_dy;
			data->pos_x += data->pos_dx;
			if (data->map_arr[(int)(data->pos_x / data->map_width) - 1][(int)(data->pos_y / data->map_height) - 1] != '1')
				data->map_arr[(int)(data->pos_x / data->map_width) - 1][(int)(data->pos_y / data->map_height) - 1] = data->spawn_dir;
		}
	}
	if (key == KEY_DOWN || key == KEY_DOWN_LINUX)
	{
		if ((int)(data->pos_x / data->map_width) > 0 && (int)(data->pos_x / data->map_width) < data->map_width - 1)
		{
			if (data->map_arr[(int)(data->pos_x / data->map_width) - 1][(int)(data->pos_y / data->map_height) - 1] != '1')
				data->map_arr[(int)(data->pos_x / data->map_width) - 1][(int)(data->pos_y / data->map_height) - 1] = '0';
			data->pos_y += 1;
			data->pos_y -= data->pos_dy;
			data->pos_x -= data->pos_dx;
			if (data->map_arr[(int)(data->pos_x / data->map_width) - 1][(int)(data->pos_y / data->map_height) - 1] != '1')
				data->map_arr[(int)(data->pos_x / data->map_width) - 1][(int)(data->pos_y / data->map_height) - 1] = data->spawn_dir;
		}
	}
	if (key == KEY_LEFT || key == KEY_LEFT_LINUX)
	{
		data->pos_ang -= 0.1;
		if (data->pos_ang < 0)
			data->pos_ang += 2 * PI;
		data->pos_dx = 5 * cos(data->pos_ang);
		data->pos_dy = 5 * sin(data->pos_ang);
	}
	if (key == KEY_RIGHT || key == KEY_RIGHT_LINUX)
	{
		data->pos_ang += 0.1;
		if (data->pos_ang > 2 * PI)
			data->pos_ang -= 2 * PI;
		data->pos_dx = 5 * cos(data->pos_ang);
		data->pos_dy = 5 * sin(data->pos_ang);
	}
	if (key == KEY_ESC || key == KEY_ESC_LINUX)
		esc_window(key, data);
	if (key == KEY_M || key == KEY_M_LINUX)
		toggle_minimap(data);
	draw_player(data, data->pos_x, data->pos_y);
	printf("position in map : [%i][%i]\nposition on screen [%f][%f]\n", (int)(data->pos_x / data->map_width), (int)(data->pos_y / data->map_height), data->pos_x, data->pos_y);
	draw_line(data->pos_x + 5, data->pos_y + 5,data->pos_x + data->pos_dx * 5,data->pos_y + data->pos_dy * 5, data);
	draw_ray(data);
	if (data->minimap == 1)
		draw_map(data);
	return (0);
}
