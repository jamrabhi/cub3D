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

typedef struct	s_map
{
	char *NO_path;
	char *SO_path;
	char *WE_path;
	char *EA_path;
	int F[3];
	int C[3];
}				t_map;

int	get_line(char *file_cub, t_map *map);
void	parse_line(char *file_cub, t_map *map);
void	print_error(char *error);
void	get_NO(const char *line, t_map *map);
void	get_SO(const char *line, t_map *map);
void	get_WE(const char *line, t_map *map);
void	get_EA(const char *line, t_map *map);
void	get_F_RGB(const char *line, t_map *map);
void	get_C_RGB(const char *line, t_map *map);

#endif
