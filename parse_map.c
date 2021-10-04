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

char	*get_array(char *line, int fd)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	str = ft_strdup("");
	while (get_next_line(fd, &line))
	{
		tmp = ft_strjoin(line, "\n");
		tmp2 = ft_strjoin(str, tmp);
		free(str);
		str = ft_strdup(tmp2);
		free(line);
		free(tmp);
		free(tmp2);
	}
	free(line);
	close(fd);
	return (str);
}

void	parse_map(char *line, int fd)
{
	char	*map_str;
	char	**map_array;

	map_str = get_array(line, fd);
	if (!map_str)
		print_error("invalid map");
	map_array = ft_split(map_str, '\n');
	if (!(check_valid_map(map_str, &map) && check_first_line(map_array)
			&& check_last_line(map_array) && check_borders(map_array)
			&& check_map(map_array)))
	{
		free(map_str);
		print_error_n_free_array("Invalid map", map_array);
	}
	free(map_str);
	free_array(map_array);
}
