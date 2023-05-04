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

#include <cub3D.h>
#include "mlx.h"

static int	raycasting(t_data *data, int x, int side)
{
	init_raycasting(data, x);
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->player_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->player_x) \
			* data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->player_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->player_y) \
			* data->delta_dist_y;
	}
	side = dda_loop(data, side);
	return (side);
}

static void	wall_calculation(t_data *data, int side)
{
	if (side == 0)
		data->perpwall_dist = fabs((data->map_x - data->player_x + \
			(1 - data->step_x) / 2) / data->ray_dir_x);
	else
		data->perpwall_dist = fabs((data->map_y - data->player_y + \
			(1 - data->step_y) / 2) / data->ray_dir_y);
	data->dist_to_wall = data->perpwall_dist * cos((data->player_dir - \
		(data->player_dir + data->camera_x * data->fov)) * PI / 180.0);
	data->wall_height = (int)(SCREENSIZE / (data->dist_to_wall * \
		cos(data->camera_x * data->fov)));
	data->draw_start = SCREENSIZE / 2 - data->wall_height / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->wall_height / 2 + SCREENSIZE / 2;
	if (data->draw_end >= SCREENSIZE)
		data->draw_end = SCREENSIZE - 1;
}

static int	choose_tex(t_data *data, int tex_num, int side)
{
	if (side == 0 && data->ray_dir_x > 0)
		tex_num = 1;
	else if (side == 0 && data->ray_dir_x < 0)
		tex_num = 0;
	else if (side == 1 && data->ray_dir_y > 0)
		tex_num = 3;
	else
		tex_num = 2;
	return (tex_num);
}

static void	wall_rendering(t_data *data, int x, int side)
{
	int	y;
	int	tex_num;

	y = 0;
	tex_num = 0;
	while (y < SCREENSIZE)
	{
		if (y < data->draw_start)
			data->game_frame[data->current_game_frame]->addr[\
				y * SCREENSIZE + x] = data->ceiling_color;
		else if (y > data->draw_end)
			data->game_frame[data->current_game_frame]->addr[\
				y * SCREENSIZE + x] = data->floor_color;
		else
		{
			tex_num = choose_tex(data, tex_num, side);
			data->game_frame[data->current_game_frame]->addr[\
				y * SCREENSIZE + x] = get_tex_color(data, side, y, tex_num);
		}
		y++;
	}
}

void	draw_walls(t_data *data)
{
	int		x;
	int		side;

	x = 0;
	side = 0;
	ft_memset(data->game_frame[data->current_game_frame]->addr, 0, \
		data->game_frame[data->current_game_frame]->sl * SCREENSIZE);
	handle_keys(data);
	while (x < SCREENSIZE)
	{
		side = raycasting(data, x, side);
		wall_calculation(data, side);
		wall_rendering(data, x, side);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->game_frame[data->current_game_frame]->img, 0, 0);
	data->current_game_frame = (data->current_game_frame + 1) % 2;
}
