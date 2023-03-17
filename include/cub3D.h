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

# define KEY_F 3
# define KEY_H 4
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_SIX 22
# define KEY_FIVE 23
# define KEY_NINE 25
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_ZERO 29
# define KEY_BRACE_R 30
# define KEY_O 31
# define KEY_U 32
# define KEY_BRACE_L 33
# define KEY_I 34
# define KEY_P 35
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_SEMI 41
# define KEY_N 45
# define KEY_TAB 48
# define KEY_PLUS 69
# define KEY_MINUS 78

/*
** CONSTANTS
*/

# define WIN_HEIGHT 1920
# define WIN_WIDTH 1080
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

typedef struct	s_img
{
	void		*img;
	int			*addr;
	int			endian;
	int			height;
	int			width;
	int			bpp;
	int			sl;
}				t_img;

typedef struct  s_ray
{
    double      wall_dist;
    double      d_dist_x;
    double      d_dist_y;
    double      camera_x;
    double      rdir_y;
    double      rdir_x;
    double      dist_x;
    double      dist_y;
    int         step_x;
    int         step_y;
    int         map_x;
    int         map_y;
    int         side;
    int         hit;
    int         tex_x;;
    int         lower_pix;
    int         higher_pix;
    int         wall_height;
}               t_ray;

typedef struct s_data
{
    /*
    ** PARSING
    */
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor[3];
	int		ceiling[3];
	int		resolution;
	char	spawn_dir;
	char	**map_arr;

    /*
    ** FILE DESCRIPTORS
    */
	int		map_fd;
	int		NO_fd;
	int		SO_fd;
	int		WE_fd;
	int		EA_fd;

    /*
    ** MLX
    */
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		l;
	t_img		m;
	t_img		so;
	t_img		no;
	t_img		ea;
	t_img		we;
	t_img		sprite;
	t_img		gun;
	void		*wall_img;
	void		*empty_img;
	void		*player_img;



	/*
	** MINIMAP
	*/
	t_img		wall;
	t_img		path;
	int			minimap;

	/*
	** PLAYER
	*/
	t_img		player;
	int			pos_x;
	int			pos_y;
	float		player_pos_x;
	float		player_pos_y;
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
int 	check_resolution(int x, int y);
void	draw_background(t_data *data, int top_color, int bottom_color);
void	draw_player(t_data *data, int px, int py);

/*
** MINIMAP
*/
void	draw_map(t_data *data);
void	create_image(t_img *img, t_data *d, int resolution[2], int casecolor);
void	write_pixel_data(t_img *img, int pixel, int color);

/*
** UTILS
*/
int		exit_error(char *error, t_data *data);
int		exit_error_n_free_line(char *error, char *line, t_data *data);
int		exit_error_n_free_array_n_line(char *e, char **a, char *l, t_data *d);
void	free_map_file(t_data *data);
void	free_line(char *line, t_data *data);
void	free_split(char **str);
int		free_array_and_return(char **array, int return_id);

#endif
