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

static void	show_array(t_data *data)
{
	int	i;
	// int	j;
	int	max;

	max = 0;
	i = 0;
	// j = 0;
	while (data->map_arr && data->map_arr[i])
	{
		printf("Line[%2.d] = |%s|\n", i, data->map_arr[i]);
		if ((int)ft_strlen(data->map_arr[i]) > max)
			max = ft_strlen(data->map_arr[i]);
		i++;
	}
	data->map_width = max;
	data->map_height = i;
	// i = 0;
	// while (data->map_arr && data->map_arr[i])
	// {
	// 	j = 0;
	// 	while (data->map_arr[i][j])
	// 	{
	// 		if (data->map_arr[i][j] != '1' && data->map_arr[i][j] != ' ' && data->map_arr[i][j] != '0')
	// 		{
	// 			printf("found player at %i %i\n", i, j);
	// 			data->pos_x = (float)(i * (data->resolution / data->map_height));
	// 			data->pos_y = (float)(j * (data->resolution / data->map_width));
	// 			printf("placing playe at %i(%i / %i) %i(%i /%i)\n", (int)data->pos_x, data->resolution, data->map_width,(int)data->pos_y, data->resolution, data->map_height);
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
}

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
	show_array(data);
	printf("-------------------------\n_________________________\n");
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
	data->wall.img = NULL;
	data->path.img = NULL;
	data->player.img = NULL;
	data->resolution = check_resolution(WIN_WIDTH, WIN_HEIGHT);

	data->pos_ang = 0;
	data->pos_dx = 0;
	data->pos_dy = 0;
	data->pos_x = 200;
	data->pos_y = 200;
	data->minimap = 1;	
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

int	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
		data->resolution, data->resolution, "cub3D");
	if (!data->mlx_ptr || !data->win_ptr)
		return (0);
	// draw_background(data, 0xF0F8FF, 0x808080);
	draw_background(data, 0x0, 0x0);
	draw_player(data, data->pos_x, data->pos_y);
	draw_map(data);
	mlx_hook(data->win_ptr, 2, (1L << 0), key_stroke, data);
	mlx_hook(data->win_ptr, 17, 0, cross_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
