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

static void	file_report(t_data *data)
{
	printf("-------------------------\n_________________________\n");
	printf("INFO DATA STRUCT. :\n");
	printf("NO : '%s'\n", data->no_path);
	printf("SO : '%s'\n", data->so_path);
	printf("WE : '%s'\n", data->we_path);
	printf("EA : '%s'\n", data->ea_path);
	printf("FLOOR : R = '%d', G= '%d', B = '%d'\n", \
		data->floor[0], data->floor[1], data->floor[2]);
	printf("CEILING : R = '%d', G= '%d', B = '%d'\n", \
		data->ceiling[0], data->ceiling[1], data->ceiling[2]);
	printf("SPAWNING ORIENTATION : '%c'\n", data->spawn_dir);
	printf("MAP :\n");
	printf("-------------------------\n_________________________\n");
	int i = 0, j= 0;
	while (data->map_arr[i])
	{
		while (data->map_arr[i][j])
		{
			if (data->map_arr[i][j] == 'N')
			{
				data->playerX = i;
				data->playerY = j;
				data->map_arr[i][j] = '0';
				return ;
			}
			j++;
		}
		j = 0;
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

	data->playerDir = 0;
	data->planeX = 0;
	data->planeY = 0.66;
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
	file_report(data);
}

static void init_player_values(t_data *data)
{
	data->planeX = 0;
	data->planeY = 0.66;
	data->dirX = -1;
	data->dirY = 0;
	data->fov = FOV;
	data->ceiling_color = 0xF0F8FF;
	data->floor_color = 0x808080;
	data->rayAngle = 0;
	data->buffer[0] = (t_img *)malloc(sizeof(t_img));
    data->buffer[0]->img = mlx_new_image(data->mlx_ptr, SCREENSIZE, SCREENSIZE);
    data->buffer[0]->addr = (int *)mlx_get_data_addr(data->buffer[0]->img, &data->buffer[0]->bpp, &data->buffer[0]->sl, &data->buffer[0]->endian);
    data->buffer[1] = (t_img *)malloc(sizeof(t_img));
    data->buffer[1]->img = mlx_new_image(data->mlx_ptr, SCREENSIZE, SCREENSIZE);
    data->buffer[1]->addr = (int *)mlx_get_data_addr(data->buffer[1]->img, &data->buffer[1]->bpp, &data->buffer[1]->sl, &data->buffer[1]->endian);
    data->current_buffer = 0;
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
	// draw_map(data);
	mlx_hook(data->win_ptr, 2, (1L << 0), key_stroke, data);
	mlx_hook(data->win_ptr, 17, 0, cross_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
