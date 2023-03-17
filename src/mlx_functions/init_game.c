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
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->no_path = NULL;
	data->so_path = NULL;
	data->we_path = NULL;
	data->ea_path = NULL;
	data->map_arr = NULL;
	data->player.img = NULL;
}

static void	show_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		printf("Line[%2.d] = |%s|\n", i, array[i]);
		i++;
	}
}

static void	file_report(t_data data)
{
	printf("-------------------------\n_________________________\n");
	printf("INFO DATA STRUCT. :\n");
	printf("NO : '%s'\n", data.no_path);
	printf("SO : '%s'\n", data.so_path);
	printf("WE : '%s'\n", data.we_path);
	printf("EA : '%s'\n", data.ea_path);
	printf("FLOOR : R = '%d', G= '%d', B = '%d'\n", data.floor[0], data.floor[1], data.floor[2]);
	printf("CEILING : R = '%d', G= '%d', B = '%d'\n", data.ceiling[0], data.ceiling[1], data.ceiling[2]);
	printf("SPAWNING ORIENTATION : '%c'\n", data.spawn_dir);
	printf("MAP :\n");
	show_array(data.map_arr);
	printf("-------------------------\n_________________________\n");
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
	file_report(*data);
}

int	init_game(t_data *data)
{
	data->resolution = check_resolution(WIN_WIDTH, WIN_HEIGHT);
	if (!(data->mlx_ptr = mlx_init()))
		return (0);
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr, data->resolution, data->resolution, "cub3D")))
		return (0);
	data->pos_x = 30;
	data->pos_y = 30;
	mlx_hook(data->win_ptr, 2, 0, key_stroke, data);
	mlx_hook(data->win_ptr, 17, 0, cross_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
