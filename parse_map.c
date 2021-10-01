/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:22:18 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/09/08 19:22:22 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		fd;
t_map	map;

/*
int	check_max_length(char *str)
{
	int	i;
	int	counter;
	int	max_length;

	i = 0;
	counter = 0;
	max_length = 0;
	while (str[i])
	{
		i++;
		if (str[i - 1] != '\n' && str[i - 1] != ' ')
			counter++;
		if (max_length < counter)
			max_length = counter;
		if (str[i] == '\n')
		{
			counter = 0;
			i++;
		}
	}
	return (max_length);
}
*/

int	empty_space(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if ((map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' ||
					map[i][j] == 'E' || map[i][j] == 'W') && (!(empty_space(map
					[i][j + 1]) && empty_space(map[i - 1][j]) &&
					empty_space(map[i + 1][j]))))
			{
				//printf("MAP i+1 = '%s'\n", map[i+1 ]);
				//printf("line = '%d' - pos = '%d' - j = '%c' - j+1 = '%c' - i-1 = '%c'  i+1 = '%c'\n",i, j, map[i][j], map[i][j+1], map[i-1][j], map[i+1][j]);
				return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

void	parse_map(char *line, int fd)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**map_array;

	i = 0;
	str = ft_strdup("");
	while (get_next_line(fd, &line))
	{
		tmp = ft_strjoin(line, "\n");
		free(str);
		str = NULL;
		str = ft_strjoin(str, tmp);
		free(line);
		free(tmp);
		tmp = NULL;
		i++;
	}
	free(line);
	if (str)
	{
		map_array = ft_split(str, '\n');
		if (!(check_valid_map(str, &map) && check_first_line(map_array)
				&& check_last_line(map_array) && check_borders(map_array)
				&& check_map(map_array)))
			print_error_n_free_array_n_line("Invalid map", map_array, line, fd);
		free(str);
		free_array(map_array);
	}
}
