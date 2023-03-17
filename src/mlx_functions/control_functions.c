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
	(void)key;
	t_data	*data;

	data = (t_data *)params;
	if(data->mlx_ptr != NULL && data->win_ptr != NULL)
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

int	key_stroke(int key, void *params)
{
	t_data	*data;

	data = (t_data *)params;
	draw_background(data, 0xF0F8FF, 0x808080); //convert colors to RGB
	if (key == KEY_W)
		printf("Pressed W.\n");
	if (key == KEY_S)
		printf("Pressed S.\n");
	if (key == KEY_A)
		printf("Pressed A.\n");
	if (key == KEY_D)
		printf("Pressed D.\n");
	if (key == KEY_LEFT)
	{
		printf("Pressed left.\n");
		draw_player(data, data->pos_x - 5, data->pos_y);
	}
	if (key == KEY_RIGHT)
	{
		printf("Pressed right.\n");
		draw_player(data, data->pos_x + 5, data->pos_y);
	}
	if (key == KEY_UP)
	{
		printf("Pressed up.\n");
		draw_player(data, data->pos_x, data->pos_y - 5);
	}
	if (key == KEY_DOWN)
	{
		printf("Pressed down.\n");
		draw_player(data, data->pos_x, data->pos_y + 5);
	}
	if (key == KEY_ESC)
		esc_window(key, data);
	return (0);
}
