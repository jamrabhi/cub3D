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
	printf("Error : %s\n", error);
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
		print_error("Incorrect file format");
}

int	check_elements(t_map *map)
{
	if (map->no_path && map->so_path && map->ea_path && map->we_path
		&& map->f[0] > -1 && map->c[0] > -1)
		return (1);
	return (0);
}

int	check_empty_line(char *str)
{
	int	i;

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
	char	*str;

	fd = open(file_cub, O_RDONLY);
	if (fd == -1)
		print_error("File doesn't exist");
	check_cub(file_cub);
	map->f[0] = -1;
	map->c[0] = -1;
	while (check_elements(map) == 0 && get_next_line(fd, &line))
	{
		if ((!(get_no(line, map) || get_so(line, map) || get_we(line, map)
					|| get_ea(line, map) || get_f_rgb(line, map) || get_c_rgb(
						line, map))) && !check_empty_line(line))
			print_error("Incorrect element in the .cub scene");
	}
	if (!check_elements(map))
		print_error("Missing element in the .cub scene");
	str = ft_strdup("");
	while (get_next_line(fd, &line))
	{
		line = ft_strjoin(line, "\n");
		str = ft_strjoin(str, line);
	}
	parse_map(str, map);
}
