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

int	print_error(char *error)
{
	printf("Erreur : %s", error);
	exit (EXIT_FAILURE);
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

int	check_elements(t_map *map)
{
	if (map->NO_path && map->SO_path && map->EA_path && map->WE_path
		&& map->F[0] > -1 && map->C[0] > -1)
		return (1);
	return (0);
}

int check_empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
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
	while (check_elements(map) == 0 && get_next_line(fd, &line))
	{
		if ((!(get_NO(line, map) || get_SO(line, map) || get_WE(line, map) ||
			get_EA(line, map) || get_F_RGB(line, map) || get_C_RGB(line, map)))
			&& !check_empty_line(line))
			print_error("Fichier .cub incorresdsdsdct");
	}
	if (!check_elements(map))
		print_error("Fichier .cub incorrect");
	while (get_next_line(fd, &line))
		printf("line = '%s'\n", line);
}
