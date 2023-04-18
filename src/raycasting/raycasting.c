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
		(data->player_dir + data->camera_x * data->fov)) * M_PI / 180.0);
	data->wall_height = (int)(SCREENSIZE / (data->dist_to_wall * \
		cos(data->camera_x * data->fov)));
	data->draw_start = SCREENSIZE / 2 - data->wall_height / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->wall_height / 2 + SCREENSIZE / 2;
	if (data->draw_end >= SCREENSIZE)
		data->draw_end = SCREENSIZE - 1;
}

// static int get_tex_color(t_data *d, int y, int side)
// {
//     t_img tex;
//     double tex_y;
//     double tex_x;
//     int lineheight;

//     lineheight = (int)(SCREENSIZE / d->perpwall_dist);
//     // if (side == 0)
//         tex.img = d->tex1.img;
//     // else if (side == 1)
//     //     tex.img = d->tex2.so_img;
//     // else if (side == 2)
//     //     tex.img = d->tex3.ea_img;
//     // else
//     //     tex.img = d->tex4.we_img;

//     char *tex_addr = mlx_get_data_addr(tex.img, &tex.bpp, &tex.sl, &tex.endian);
//     tex_y = (y * 2 - SCREENSIZE + lineheight) * (d->tex1.height / 2) / lineheight;
//     if (tex_y < 0)
//         tex_y = 0;
//     tex_x = (int)((d->player_y + d->perpwall_dist * d->ray_dir_y) * d->tex1.width) % d->tex1.width;
//     if ((side == 0 && d->ray_dir_x > 0) || (side == 1 && d->ray_dir_y < 0))
//         tex_x = d->tex1.width - tex_x - 1;
//     char *color = tex_addr + (int)tex_y * tex.sl + (int)tex_x * (tex.bpp / 8);
//     return (*(unsigned int *)color);
// }

static void	place_wall_texture(t_data *data, int side)
{
	if (side == 0)
	{
		if (data->ray_dir_x < 0)
			data->wall_color = 0xFF0000; // Red for west-facing walls
		else
			data->wall_color = 0x00FF00; // Green for east-facing walls
	}
	else
	{
		if (data->ray_dir_y < 0)
			data->wall_color = 0x0000FF; // Blue for north-facing walls
		else
			data->wall_color = 0xFFFF00; // Yellow for south-facing walls
	}	
}

static void	wall_rendering(t_data *data, int x, int side)
{
	int	y;

	y = 0;
	place_wall_texture(data, side);
	while (y < SCREENSIZE)
	{
		if (y < data->draw_start)
			data->game_frame[data->current_game_frame]->addr[y * \
				SCREENSIZE + x] = data->ceiling_color;
		else if (y > data->draw_end)
			data->game_frame[data->current_game_frame]->addr[y * \
				SCREENSIZE + x] = data->floor_color;
		else
		{
			if (side == 1)
				data->game_frame[data->current_game_frame]->addr[y * \
					SCREENSIZE + x] = data->wall_color;
			else
				data->game_frame[data->current_game_frame]->addr[y * \
					SCREENSIZE + x] = data->wall_color;
				// data->game_frame[data->current_game_frame]->addr[y * SCREENSIZE + x] = get_tex_color(data, data->draw_start + ((data->draw_end - data->draw_start) / 2), side);
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
	memset(data->game_frame[data->current_game_frame]->addr, 0, \
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
