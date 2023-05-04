/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:05:23 by dsy               #+#    #+#             */
/*   Updated: 2020/07/08 01:22:50 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_game_struct(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->no_path = NULL;
	data->so_path = NULL;
	data->we_path = NULL;
	data->ea_path = NULL;
	data->map_arr = NULL;
	data->player_orientation = 0;
	data->resolution = check_resolution(WIN_WIDTH, WIN_HEIGHT);
	data->minimap = 1;
	data->player_dir = 0;
	data->turn_left = 0;
	data->turn_right = 0;
	data->move_up = 0;
	data->move_down = 0;
}

void	load_game_settings(t_data *data, int argc, char **argv)
{
	if (argc != 2)
		exit_error("Usage: ./cub3D map.cub", data);
	data->map_fd = open(argv[1], O_DIRECTORY);
	if (data->map_fd != -1)
		exit_error("Map is a directory", data);
	data->map_fd = open(argv[1], O_RDONLY);
	if (data->map_fd == -1)
		exit_error("Map doesn't exist", data);
	parsing(argv[1], data);
}

static void	init_player_values(t_data *d)
{
	d->fov = FOV;
	d->ceiling_color = ((d->ceiling[0] & 0xff) << 16) + ((d->ceiling[1] & 0xff)
			<< 8) + (d->ceiling[2] & 0xff);
	d->floor_color = ((d->floor[0] & 0xff) << 16) + ((d->floor[1] & 0xff)
			<< 8) + (d->floor[2] & 0xff);
	d->ray_angle = 0;
	d->game_frame[0] = (t_img *)malloc(sizeof(t_img));
	d->game_frame[0]->img = mlx_new_image(d->mlx_ptr, SCREENSIZE, SCREENSIZE);
	if (!d->game_frame[0]->img)
		exit_error("MLX error", d);
	d->game_frame[0]->addr = (int *)mlx_get_data_addr(d->game_frame[0]->img, \
	&d->game_frame[0]->bpp, &d->game_frame[0]->sl, &d->game_frame[0]->endian);
	d->game_frame[1] = (t_img *)malloc(sizeof(t_img));
	d->game_frame[1]->img = mlx_new_image(d->mlx_ptr, SCREENSIZE, SCREENSIZE);
	if (!d->game_frame[1]->img)
		exit_error("MLX error", d);
	d->game_frame[1]->addr = (int *)mlx_get_data_addr(d->game_frame[1]->img, \
	&d->game_frame[1]->bpp, &d->game_frame[1]->sl, &d->game_frame[1]->endian);
	d->current_game_frame = 0;
}

void	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit_error("Failed to init MLX", data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
			data->resolution, data->resolution, "cub3D");
	if (!data->win_ptr)
		exit_error("Failed to create window", data);
	init_player_values(data);
	load_textures(data);
	if (!data->tex[0].img || !data->tex[1].img || \
		!data->tex[2].img || !data->tex[3].img)
		exit_error("Failed to load textures", data);
	get_data_addr(data);
	player_spawn(data);
	draw_walls(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_stroke, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, cross_window, data);
	mlx_loop(data->mlx_ptr);
}
