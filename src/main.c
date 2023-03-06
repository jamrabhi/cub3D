/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:41:10 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/27 21:44:32 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	show_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		printf("Line[%2.d] = |%s|\n", i, array[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	data.map = malloc(sizeof(t_map));
	ft_bzero(data.map, sizeof(t_map));
	if (argc != 2)
		exit_error("Usage: ./cub3D map.cub", &data);
	data.map_fd = open(argv[1], O_DIRECTORY);
	if (data.map_fd != -1)
		exit_error("Map is a directory", &data);
	data.map_fd = open(argv[1], O_RDONLY);
	if (data.map_fd == -1)
		exit_error("Map doesn't exist", &data);
	parsing(argv[1], &data);

	printf("-------------------------\n_________________________\n");
	printf("INFO DATA STRUCT. :\n");
	printf("NO : '%s'\n", data.map->no_path);
	printf("SO : '%s'\n", data.map->so_path);
	printf("WE : '%s'\n", data.map->we_path);
	printf("EA : '%s'\n", data.map->ea_path);
	printf("FLOOR : R = '%d', G= '%d', B = '%d'\n", data.map->f[0], data.map->f[1], data.map->f[2]);
	printf("CEILING : R = '%d', G= '%d', B = '%d'\n", data.map->c[0], data.map->c[1], data.map->c[2]);
	printf("SPAWNING ORIENTATION : '%c'\n", data.map->spawn_dir);
	printf("MAP :\n");
	show_array(data.map->map_arr);
	printf("-------------------------\n_________________________\n");

	// void	*mlx;
	// void	*mlx_win;
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// mlx_loop(mlx);
	// 	free(mlx);
	// mlx_destroy_window(mlx,mlx_win);

	free_map(&data);
	return (0);
}



//TODO : when line only space invalid read
