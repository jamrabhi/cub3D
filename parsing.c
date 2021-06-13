/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:33:00 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/13 21:34:11 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

void	print_error(char *error)
{
	printf("Erreur : %s", error);
	exit (1);
}

void	get_NO(const char *line, t_map *map)
{
	char **path;

	path = NULL;
	if (line[0] == 'N' && line[1] == 'O')
	{
		path = ft_split(line, ' ');
		map->NO_path = path[1];
		printf("%s", path[1]);
	}
	if (path[2])
		print_error("Fichier .cub incorrect");
}

void	get_SO(const char *line, t_map *map)
{
	char **path;

	path = NULL;
	if (line[0] == 'S' && line[1] == 'O')
	{
		path = ft_split(line, ' ');
		map->SO_path = path[1];
		printf("%s", path[1]);
	}
	if (path[2])
		print_error("Fichier .cub incorrect");
}

void	get_WE(const char *line, t_map *map)
{
	char **path;

	path = NULL;
	if (line[0] == 'W' && line[1] == 'E')
	{
		path = ft_split(line, ' ');
		map->WE_path = path[1];
		printf("%s", path[1]);
	}
	if (path[2])
		print_error("Fichier .cub incorrect");
}

void	get_EA(const char *line, t_map *map)
{
	char **path;

	path = NULL;
	if (line[0] == 'E' && line[1] == 'A')
	{
		path = ft_split(line, ' ');
		map->EA_path = path[1];
		printf("%s", path[1]);
	}
	if (path[2])
		print_error("Fichier .cub incorrect");
}

void	parse_line(char **file_cub, t_map *map)
{
	char *line;
	int fd;
	int ret;

	fd = open(*file_cub, O_RDONLY);
	ret = 1;
	while (ret)
	{
		get_next_line(fd, &line);
		get_NO(line, map);
		get_SO(line, map);
		get_WE(line, map);
		get_EA(line, map);
		free(line);
	}
	
}


