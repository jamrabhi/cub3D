/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:39:25 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/27 23:16:40 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

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

int		get_line(char *file_cub, t_map *map);
void	parse_line(char *file_cub, t_map *map);
int		print_error(char *error);
int		print_error_n_free_array(char *error, char **array);
int		get_no(const char *line, t_map *map);
int		get_so(const char *line, t_map *map);
int		get_we(const char *line, t_map *map);
int		get_ea(const char *line, t_map *map);
int		get_f_c_rgb(char *line, t_map *map, char c);
void	parse_map(char *str, t_map *map);
int		check_valid_map(char *str, t_map *map);
int		check_first_line(char **map);
int		check_last_line(char **map);
int		check_borders(char **map);

#endif
