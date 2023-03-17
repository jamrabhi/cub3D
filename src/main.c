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

#include "cub3D.h"

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

int	esc_window(int key, void *params)
{
	(void)key;
	t_data *data = (t_data *)params;
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
void draw_player(t_data *data, int px, int py) {
    // Calculate the size of the window and the size of each half
    // Create two images of the appropriate size
    t_img player;
    player.img = mlx_new_image(data->mlx_ptr, 10, 10);
    player.addr = (int *)mlx_get_data_addr(player.img, &player.bpp, &player.sl, &player.endian);

	int x =0, y = 0;
    // Fill the bottom image with the bottom color
    y = 0;
    while (y < 10) {
        x = 0;
        while (x < 10) {
            *(player.addr + y * (player.sl / 4) + x) = 0x000000;
            x++;
        }
        y++;
    }

    // Put the images on the window at the correct coordinates
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, player.img, px, py);
}


int	key_stroke(int key, void *params)
{
	t_data *data = (t_data *)params;
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
		draw_player(data, data->pos_x + 5, data->pos_y);
	}
	if (key == KEY_RIGHT)
	{
		printf("Pressed right.\n");
		draw_player(data, data->pos_x - 5, data->pos_y);
	}
	if (key == KEY_UP)
	{
		printf("Pressed up.\n");
		draw_player(data, data->pos_x, data->pos_y + 5);
	}
	if (key == KEY_DOWN)
	{
		printf("Pressed down.\n");
		draw_player(data, data->pos_x, data->pos_y - 5);
	}
	if (key == KEY_ESC)
		esc_window(key, data);
	return (0);
}

static int check_resolution(int x, int y)
{
	int res;

	if (x > y)
		res = x;
	else
		res = y;
	if (res > 960)
		return (960);
	if (res < 320)
		return (320);
	return (res);
}

void draw_background(t_data *data, int resolution, int top_color, int bottom_color) {
    // Calculate the size of the window and the size of each half
    int width = resolution;
    int height = resolution;
    int half_height = height / 2;

    // Create two images of the appropriate size
    t_img top_img;
    top_img.img = mlx_new_image(data->mlx_ptr, width, half_height);
    top_img.addr = (int *)mlx_get_data_addr(top_img.img, &top_img.bpp, &top_img.sl, &top_img.endian);

    t_img bottom_img;
    bottom_img.img = mlx_new_image(data->mlx_ptr, width, half_height);
    bottom_img.addr = (int *)mlx_get_data_addr(bottom_img.img, &bottom_img.bpp, &bottom_img.sl, &bottom_img.endian);

    // Fill the top image with the top color
    int x, y;
    y = 0;
    while (y < half_height) {
        x = 0;
        while (x < width) {
            *(top_img.addr + y * (top_img.sl / 4) + x) = top_color;
            x++;
        }
        y++;
    }

    // Fill the bottom image with the bottom color
    y = 0;
    while (y < half_height) {
        x = 0;
        while (x < width) {
            *(bottom_img.addr + y * (bottom_img.sl / 4) + x) = bottom_color;
            x++;
        }
        y++;
    }

    // Put the images on the window at the correct coordinates
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, top_img.img, 0, 0);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, bottom_img.img, 0, resolution / 2);
}


int	init_game(t_data *data)
{
	int	resolution;

	resolution = check_resolution(WIN_WIDTH, WIN_HEIGHT);

	if (!(data->mlx_ptr = mlx_init()))
		return (0);
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr, resolution, resolution, "cub3D")))
		return (0);

	draw_background(data, resolution, 0xF0F8FF, 0x808080); //convert colors to RGB
	data->pos_x = 30;
	data->pos_y = 30;
	draw_player(data, data->pos_x, data->pos_y);

	mlx_hook(data->win_ptr, 2, 0, key_stroke, data);
	mlx_hook(data->win_ptr, 17, 0, cross_window, data);
	//mlx_loop_hook(data->mlx_ptr, raycasting, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

static void	load_game_settings(t_data *data, int argc, char **argv)
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

void	init_game_struct(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->no_path = NULL;
	data->so_path = NULL;
	data->we_path = NULL;
	data->ea_path = NULL;
	data->map_arr = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_game_struct(&data);
	load_game_settings(&data, argc, argv);
	if (!(init_game(&data)))
	{
		write(1, "Error\n[MLX]Connection to MLX failed.\n", 37);
		return (0);
	}
	free_map_file(&data);
	return (0);
}
