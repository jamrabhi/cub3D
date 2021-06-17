/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:33:00 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/17 21:38:23 by jamrabhi         ###   ########.fr       */
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
	char	**path;

	//if (line)
	path = ft_split(line, ' ');
	if (line && path[0] && (ft_strncmp(path[0], "NO", 2) == 0))
	{
		if (path[2] || map->NO_path)
			print_error("Fichier .cub incorrect");
		map->NO_path = path[1];
	}
}

void	get_SO(const char *line, t_map *map)
{
	char	**path;

	//if (line)
	path = ft_split(line, ' ');
	if (line && path[0] && (ft_strncmp(path[0], "SO", 2) == 0))
	{
		if (path[2] || map->SO_path)
			print_error("Fichier .cub incorrect");
		map->SO_path = path[1];
	}
}

void	get_WE(const char *line, t_map *map)
{
	char	**path;

	//if (line)
	path = ft_split(line, ' ');
	if (line && path[0] && (ft_strncmp(path[0], "WE", 2) == 0))
	{
		if (path[2] || map->WE_path)
			print_error("Fichier .cub incorrect");
		map->WE_path = path[1];
	}
}

void	get_EA(const char *line, t_map *map)
{
	char	**path;

	//if (line)
	path = ft_split(line, ' ');
	if (line &&  path[0] && (ft_strncmp(path[0], "EA", 2) == 0))//line pr espace
	{
		if (path[2] || map->EA_path)
			print_error("Fichier .cub incorrect");
		map->EA_path = path[1];
	}
}

void	get_F_RGB(const char *line)
{
	char	**numbers;

	numbers = ft_split(line, ' ');
	if (line && numbers[0] && (ft_strncmp(numbers[0], "F", 1) == 0))
	{
		numbers = ft_split(numbers[1], ',');
		printf("%s\n",numbers[0]);
		if (numbers[2] && !numbers[3] && ft_isdigit(numbers[0] && ft)!!!!!!!!!!!!!!!!
			
	}

}

void	parse_line(char *file_cub, t_map *map)
{
	char *line;
	int fd;

	fd = open(file_cub, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		get_NO(line, map);
		get_SO(line, map);
		get_WE(line, map);
		get_EA(line, map);
		get_F_RGB(line);
	}
}
