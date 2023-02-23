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

# include "../src/get_next_line/get_next_line.h"
# include <libft.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

# define INVALID_ELEM "Invalid element in the .cub file"
# define MISSING_ELEM "Missing element in the .cub file"
# define INVALID_FILE "Invalid file format"
# define INVALID_RGB "Invalide RGB values"

typedef struct s_map
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		f[3];
	int		c[3];
	char	spawn_dir;
}				t_map;

typedef struct s_data
{
	t_map	*map;
	int		map_fd;
}				t_data;

void	parse_line(char *file_cub, t_data *data);

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

int		exit_error(char *error, t_data *data);
int		exit_error_n_free_line(char *error, char *line, t_data *data);
int		exit_error_n_free_array_n_line(char *e, char **a, char *l, t_data *d);
void	free_map(t_data *data);
void	free_line(char *line, t_data *data);
void	free_array(char **str);
int		free_array_and_return(char **array, int return_id);

void	show_array(char **array);

#endif
