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

int	check_valid_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '0' || str[i] == '1' || str[i] == 'N' || str[i] == 'S'
				|| str[i] == 'E' || str[i] == 'W' || str[i] == '\n'
				|| str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

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
		if (str[i - 1] != '\n' && str[i - 1] != ' ') //&& check_valid_char(&str[i-1]))
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

int	check_first_line(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
				return (0);
			else if (map[i][j] == '1')
			{
				while (map[i][j] == '1' || map[i][j] == ' ')
					j++;
				if (map[i][j])
					return 0;
				return 1;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_last_line(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	i--;
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (0);
		j++;
	}
	return (1);
}

int	check_borders(char **map)
{
	int i;
	int j;
	int last_char;

	i = 0;
	j = 0;
	last_char = (ft_strlen(map[i]) - 1);
	while (map[i])
	{
		j = 0;
		last_char = (ft_strlen(map[i]) - 1);
		if (map[i][j] == ' ' || map[i][last_char] == ' ')
		{
			while (map[i][j] && map[i][j] == ' ')
				j++;
			while (map[i][last_char] > 0 && map[i][last_char] == ' ')
				last_char--;
		}
		//printf("DEBUG line = '%d' first = '%c' last = '%c'\n", i, map[i][j], map[i][last_char]);
		if (map[i][j] != '1' || map[i][last_char] != '1')
		{
			//printf("map[%d] = '%s'\n",i, map[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

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
				printf("line = '%d' - pos = '%d' - j = '%c' - j+1 = '%c' - i-1 = '%c'  i+1 = '%c'\n",i, j, map[i][j], map[i][j+1], map[i-1][j], map[i+1][j]);
				return 0;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

void	parse_map(char *str, t_map *map)
{
	int	i;
	int j;
	char **map_array;
	
	i = 0;
	j = 0;
	map_array = ft_split(str, '\n');
	show_array(map_array);
	if (map)
		ft_isprint('0');
	if (check_valid_char(str) == 0)
		print_error("Invalid map");
	if (!(check_first_line(map_array) && check_last_line(map_array)))
		print_error("Invalid map");
	if (!check_borders(map_array))
		print_error("Invalid map (borders)");
	if (!check_map(map_array))
		print_error("Invalid map (0)");
	/*
	while (map_array[i])
	{
		if (map_array[i][j] == '0' && map_array[i][j+1] != ) 
	}
	*/
}
