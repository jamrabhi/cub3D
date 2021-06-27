/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:33:00 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/27 23:36:00 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *error)
{
	printf("Erreur : %s", error);
	exit (1);
}

void	show_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("Line[%d] = |%s|\n", i, array[i]);
		i++;
	}
}

void	check_cub(char *file_name)
{
	const char	*dot;

	dot = ft_strrchr(file_name, '.');
	if (ft_strncmp(dot, ".cub", 5) != 0)
		print_error("Fichier .cub incorrect");
}

void	parse_line(char *file_cub, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(file_cub, O_RDONLY);
	if (fd == -1)
		print_error("Fichier .cub incorrect");
	check_cub(file_cub);
	map->F[0] = -1;
	map->C[0] = -1;
	while (get_next_line(fd, &line))
	{
		get_NO(line, map);
		get_SO(line, map);
		get_WE(line, map);
		get_EA(line, map);
		get_F_RGB(line, map);
		get_C_RGB(line, map);
	}
}
