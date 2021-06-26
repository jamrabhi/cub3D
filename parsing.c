/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:33:00 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/26 18:03:59 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

void	print_error(char *error)
{
	printf("Erreur : %s", error);
	exit (1);
}

void	display(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("[%s]\n", tab[i]);
		i += 1;
	}
}

void	get_NO(const char *line, t_map *map)
{
	char	**path;

	path = ft_split(line, ' ');
	if (line && path[0] && (ft_strncmp(path[0], "NO", 2) == 0))
	{
		if (path[2] || map->NO_path)
			print_error("Fichier .cub incorrect");
		map->NO_path = path[1];
	}
	printf("line = |%s|\n", line);
}

void	get_SO(const char *line, t_map *map)
{
	char	**path;

	path = ft_split(line, ' ');
	if (line && path[0] && (ft_strncmp(path[0], "SO", 2) == 0))
	{
		if (path[2] || map->SO_path)
			print_error("Fichier .cub incorrect");
		map->SO_path = path[1];
	}
	printf("line = |%s|\n", line);
}

void	get_WE(const char *line, t_map *map)
{
	char	**path;

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

	path = ft_split(line, ' ');
	if (line && path[0] && (ft_strncmp(path[0], "EA", 2) == 0)) //line pr espace
	{
		if (path[2] || map->EA_path)
			print_error("Fichier .cub incorrect");
		map->EA_path = path[1];
	}
}

int	check_number_elements(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
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

char	*join_array(char **array)
{
	int i;
	char *str;
	char *buff;

	i = 1;
	buff = array[1];
	while (array[i + 1])
	{
		str = ft_strjoin(buff, array[i + 1]);
		buff = str;
		i++;
	}
	return str;
}

void	get_F_RGB(const char *line, t_map *map)
{
	char	**numbers;
	int		RGB[3];
	int		size;
	char *RGB_s;

	numbers = ft_split(line, ' ');
	if (line && numbers[0] && (ft_strncmp(numbers[0], "F", 1) == 0))
	{
		show_array(numbers);
		RGB_s = join_array(numbers);
		printf("RGB = ||||%s||||\n", RGB_s);
		numbers = ft_split(numbers[1], ',');
		size = check_number_elements(numbers);
		if (!(size == 3 && ft_isdigit_str(numbers[0]) && ft_isdigit_str(
					numbers[1]) && ft_isdigit_str(numbers[2])))
			print_error("Fichier .cub incorrect");
		RGB[0] = ft_atoi(numbers[0]);
		RGB[1] = ft_atoi(numbers[1]);
		RGB[2] = ft_atoi(numbers[2]);
		if (!((RGB[0] >= 0 && RGB[0] <= 255) && (RGB[1] >= 0 && RGB[1] <= 255)
				&& (RGB[2] >= 0 && RGB[2] <= 255)))
			print_error("Fichier .cub incorrect");
		map->F[0] = RGB[0];
		map->F[1] = RGB[1];
		map->F[2] = RGB[2];
	}
}

void	get_C_RGB(const char *line, t_map *map)
{
	char	**numbers;
	int		RGB[3];
	int		size;

	numbers = ft_split(line, ' ');
	if (line && numbers[0] && (ft_strncmp(numbers[0], "C", 1) == 0))
	{
		numbers = ft_split(numbers[1], ',');
		size = check_number_elements(numbers);
		if (!(size == 3 && ft_isdigit_str(numbers[0]) && ft_isdigit_str(
					numbers[1]) && ft_isdigit_str(numbers[2])))
			print_error("Fich ier .cub incorrect");
		RGB[0] = ft_atoi(numbers[0]);
		RGB[1] = ft_atoi(numbers[1]);
		RGB[2] = ft_atoi(numbers[2]);
		if (!((RGB[0] >= 0 && RGB[0] <= 255) && (RGB[1] >= 0 && RGB[1] <= 255)
				&& (RGB[2] >= 0 && RGB[2] <= 255)))
			print_error("Fich ier .cub incorrect");
		map->C[0] = RGB[0];
		map->C[1] = RGB[1];
		map->C[2] = RGB[2];
	}
}

/*
void	get_map(const char *line)
{

}
*/

void	check_cub(char *file_name)
{
	const char *dot;

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
	while (get_next_line(fd, &line))
	{
		get_NO(line, map);
		get_SO(line, map);
		get_WE(line, map);
		get_EA(line, map);
		get_F_RGB(line, map);
		get_C_RGB(line, map);
		//get_map(line);
	}
}
