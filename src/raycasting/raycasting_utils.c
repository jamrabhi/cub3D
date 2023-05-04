/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:35:17 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/02/23 19:35:20 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	handle_walk(t_data *data)
{
	double	nextplayer_x;
	double	nextplayer_y;

	if (data->move_up)
	{
		nextplayer_x = data->player_x + data->player_vel_x;
		nextplayer_y = data->player_y + data->player_vel_y;
		if (data->map_arr[(int)nextplayer_x][(int)nextplayer_y] == '0')
		{
			data->player_x = nextplayer_x;
			data->player_y = nextplayer_y;
		}
		data->move_up = 0;
	}
	if (data->move_down)
	{
		nextplayer_x = data->player_x - data->player_vel_x;
		nextplayer_y = data->player_y - data->player_vel_y;
		if (data->map_arr[(int)nextplayer_x][(int)nextplayer_y] == '0')
		{
			data->player_x = nextplayer_x;
			data->player_y = nextplayer_y;
		}
		data->move_down = 0;
	}
}

int	dda_loop(t_data *data, int side)
{
	while (!data->hit)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			side = 1;
		}
		if (data->map_arr[data->map_x][data->map_y] == '1')
			data->hit = 1;
	}
	return (side);
}

void	handle_keys(t_data *data)
{
	if (data->turn_left)
	{
		data->player_dir -= 0.1 * ROT_SPEED;
		data->turn_left = 0;
	}
	if (data->turn_right)
	{
		data->player_dir += 0.1 * ROT_SPEED;
		data->turn_right = 0;
	}
	data->player_vel_x = sin(data->player_dir) * MOVE_SPEED;
	data->player_vel_y = cos(data->player_dir) * MOVE_SPEED;
	handle_walk(data);
	if (data->player_dir < 0)
		data->player_dir += 2 * PI;
	else if (data->player_dir >= 2 * PI)
		data->player_dir -= 2 * PI;
}

void	init_raycasting(t_data *data, int x)
{
	data->camera_x = 2 * x / (double)SCREENSIZE - 1;
	data->ray_dir_x = sin(data->player_dir + data->fov \
		* data->camera_x) + 0.001;
	data->ray_dir_y = cos(data->player_dir + data->fov \
		* data->camera_x) + 0.001;
	data->map_x = (int)data->player_x;
	data->map_y = (int)data->player_y;
	if (data->ray_dir_x == 0)
		data->ray_dir_x = 1;
	if (data->ray_dir_y == 0)
		data->ray_dir_y = 1;
	data->delta_dist_x = fabs(1 / data->ray_dir_x);
	data->delta_dist_y = fabs(1 / data->ray_dir_y);
	data->hit = 0;
}
