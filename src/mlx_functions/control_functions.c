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

int	esc_window(void *params)
{
	t_data	*data;

	data = (t_data *)params;
	printf("Exit (esc).\n");
	free_mlx(data);
	free_map_file(data);
	exit(EXIT_SUCCESS);
}

int	cross_window(void *params)
{
	t_data	*data;

	data = (t_data *)params;
	printf("Exit (cross).\n");
	free_mlx(data);
	free_map_file(data);
	exit(EXIT_SUCCESS);
}

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
		esc_window(data);
	draw_walls(data);
	return (0);
}
