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

static void	player_spawn(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->map_arr[i])
	{
		j = 0;
		while (data->map_arr[i][j])
		{
			if (data->map_arr[i][j] == 'N')
			{
				data->player_x = i;
				data->player_y = j;
				data->map_arr[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_game_struct(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->no_path = NULL;
	data->so_path = NULL;
	data->we_path = NULL;
	data->ea_path = NULL;
	data->map_arr = NULL;
	data->resolution = check_resolution(WIN_WIDTH, WIN_HEIGHT);
	data->minimap = 1;
	data->player_dir = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
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
	player_spawn(data);
}

static void	init_player_values(t_data *d)
{
	d->plane_x = 0;
	d->plane_y = 0.66;
	d->dir_x = -1;
	d->dir_y = 0;
	d->fov = FOV;
	d->ceiling_color = 0xD65D42;
	d->floor_color = 0x803333;
	d->ray_angle = 0;
	d->game_frame[0] = (t_img *)malloc(sizeof(t_img));
	d->game_frame[0]->img = mlx_new_image(d->mlx_ptr, SCREENSIZE, SCREENSIZE);
	d->game_frame[0]->addr = (int *)mlx_get_data_addr(d->game_frame[0]->img, \
	&d->game_frame[0]->bpp, &d->game_frame[0]->sl, &d->game_frame[0]->endian);
	d->game_frame[1] = (t_img *)malloc(sizeof(t_img));
	d->game_frame[1]->img = mlx_new_image(d->mlx_ptr, SCREENSIZE, SCREENSIZE);
	d->game_frame[1]->addr = (int *)mlx_get_data_addr(d->game_frame[1]->img, \
	&d->game_frame[1]->bpp, &d->game_frame[1]->sl, &d->game_frame[1]->endian);
	d->current_game_frame = 0;
}

int	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
			data->resolution, data->resolution, "cub3D");
	if (!data->mlx_ptr || !data->win_ptr)
		return (0);
	init_player_values(data);
	draw_walls(data);
        data->tex1.img = mlx_xpm_file_to_image(data->mlx_ptr, data->no_path, &data->tex1.width, &data->tex1.height);
        data->tex2.img = mlx_xpm_file_to_image(data->mlx_ptr, data->so_path, &data->tex2.width, &data->tex2.height);
        data->tex3.img = mlx_xpm_file_to_image(data->mlx_ptr, data->ea_path, &data->tex3.width, &data->tex3.height);
        data->tex4.img = mlx_xpm_file_to_image(data->mlx_ptr, data->we_path, &data->tex4.width, &data->tex4.height);
	mlx_hook(data->win_ptr, 2, (1L << 0), key_stroke, data);
	mlx_hook(data->win_ptr, 17, 0, cross_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
