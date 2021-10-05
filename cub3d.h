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

extern t_map	g_map;
extern int		g_fd;

void	parse_line(char *file_cub);
int		print_error(char *error);
int		print_error_n_free_array_n_line(char *error, char **array, char *line);
int		get_no(char *line);
int		get_so(char *line);
int		get_we(char *line);
int		get_ea(char *line);
int		get_f_c_rgb(char *line, char c);
void	parse_map(char *line);
int		check_valid_map(char *str);
int		check_first_line(char **map);
int		check_last_line(char **map);
int		check_borders(char **map);
int		free_array_and_return(char **array, int return_id);
void	free_array(char **str);
void	free_array_n_line(char **str, char *line);
void	show_array(char **array);
int		print_error_n_free_array(char *error, char **array);

#endif
