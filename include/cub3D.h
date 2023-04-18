/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:11:24 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/01/26 17:11:29 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
** KEY MAPPINGS
*/

# define MOVE_SPEED 0.5
# define ROT_SPEED 1

# define SCREENSIZE 800

# define PI 3.14159263
# define P2 1.570796315
# define P3 4.712388945
# define FOV 0.34906584777

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define KEY_ESC_LINUX 65307
# define KEY_W_LINUX 119
# define KEY_A_LINUX 97
# define KEY_S_LINUX 115
# define KEY_D_LINUX 100
# define KEY_LEFT_LINUX 65361
# define KEY_RIGHT_LINUX 65363
# define KEY_DOWN_LINUX 65364
# define KEY_UP_LINUX 65362

# define KEY_M 46
# define KEY_M_LINUX 109

/*
** CONSTANTS
*/

# define WIN_HEIGHT SCREENSIZE
# define WIN_WIDTH SCREENSIZE
# define INVALID_FILE "Invalid file format"
# define INVALID_CUB "Invalid or missing element in the .cub file"
# define INVALID_RGB "Invalid RGB values"
# define MISCONF_NO "Misconfiguration in the .cub file (NO texture)"
# define MISCONF_SO "Misconfiguration in the .cub file (SO texture)"
# define MISCONF_WE "Misconfiguration in the .cub file (WE texture)"
# define MISCONF_EA "Misconfiguration in the .cub file (EA texture)"
# define NO_IS_DIR "North texture is a directory"
# define SO_IS_DIR "South texture is a directory"
# define WE_IS_DIR "West texture is a directory"
# define EA_IS_DIR "East texture is a directory"
# define NO_UNAV "North texture doesn't exist"
# define SO_UNAV "South texture doesn't exist"
# define WE_UNAV "West texture doesn't exist"
# define EA_UNAV "East texture doesn't exist"

/*
** LIBS
*/

# include "../src/get_next_line/get_next_line.h"
# include <sys/types.h>
# include <unistd.h>
# include <libft.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

/*
** STRUCTURES
*/

typedef struct s_tex
{
	void		*img;
	int			*addr;
	int			width;
	int			height;
}				t_tex;

typedef struct s_img
{
	void		*img;
	int			*addr;
	int			endian;
	int			height;
	int			width;
	int			bpp;
	int			sl;
}				t_img;

typedef struct s_data
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	int			floor[3];
	int			ceiling[3];
	int			resolution;
	int			map_width;
	int			map_height;
	char		spawn_dir;
	char		**map_arr;

	int			map_fd;
	int			no_fd;
	int			so_fd;
	int			we_fd;
	int			ea_fd;

	void		*mlx_ptr;
	void		*win_ptr;

	int			minimap;

	int			current_game_frame;
	t_img		*game_frame[2];
	double		player_dir;
	double		player_x;
	double		player_y;
	double		player_vel_x;
	double		player_vel_y;
	double		plane_x;
	double		plane_y;
	int			dir_x;
	int			dir_y;
	double		fov;
	double		ray_angle;
	int			ceiling_color;
	int			floor_color;
	int			turn_right;
	int			turn_left;
	int			move_up;
	int			move_down;

	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	int			hit;

	double		perpwall_dist;
	double		dist_to_wall;
	int			wall_height;
	int			draw_start;
	int			draw_end;
	int			wall_color;

	t_tex		tex1;
	t_tex		tex2;
	t_tex		tex3;
	t_tex		tex4;
}				t_data;

/*
** PARSING
*/
void	parsing(char *file_cub, t_data *data);
int		get_no(char *line, t_data *data);
int		get_so(char *line, t_data *data);
int		get_we(char *line, t_data *data);
int		get_ea(char *line, t_data *data);
int		get_f_c_rgb(char *line, char c, t_data *data);
void	parse_map(char *line, t_data *data);
int		check_valid_map(char *str, t_data *data);
int		check_first_line(char **map);
int		check_last_line(char **map);
int		check_borders(char **map);

/*
** INIT
*/
int		init_game(t_data *data);
void	init_game_struct(t_data *data);
void	load_game_settings(t_data *data, int argc, char **argv);

/*
** MLX
*/
int		esc_window(int key, void *params);
int		cross_window(int key, void *params);
int		key_stroke(int key, void *params);
int		check_resolution(int x, int y);

/*
** RAYCASTING
*/
void	init_raycasting(t_data *data, int x);
void	draw_walls(t_data *data);
int		dda_loop(t_data *data, int side);

/*
** MINIMAP
*/
void	draw_map(t_data *data);
void	create_image(t_img *img, t_data *d, int resolution[2], int casecolor);
void	write_pixel_data(t_img *img, int pixel, int color);

/*
** UTILS
*/
void	handle_keys(t_data *data);
int		exit_error(char *error, t_data *data);
int		exit_error_n_free_line(char *error, char *line, t_data *data);
int		exit_error_n_free_array_n_line(char *e, char **a, char *l, t_data *d);
void	free_map_file(t_data *data);
void	free_line(char *line, t_data *data);
void	free_split(char **str);
int		free_array_and_return(char **array, int return_id);

#endif