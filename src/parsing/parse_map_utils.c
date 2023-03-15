/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:07:06 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/09/20 21:07:08 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	is_end(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_valid_map(char *str, t_data *data)
{
	int	i;
	int	wall_count;

	i = 0;
	wall_count = 0;
	data->spawn_dir = 0;
	while (str && str[i])
	{
		if (!(str[i] == '0' || str[i] == '1' || str[i] == '\n' || str[i] == ' ')
			&& ((str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i]
					== 'W') && data->spawn_dir != 0))
			return (0);
		if (str[i] == '1')
			wall_count++;
		if (wall_count > 0 && (str[i] == '\n' && ((str[i + 1] && str[i + 1]
						== '\n')) && !is_end(&str[i])))
			return (0);
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			data->spawn_dir = str[i];
		i++;
	}
	if (data->spawn_dir == 0)
		return (0);
	return (1);
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
					return (0);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_last_line(char **map)
{
	int	i;
	int	j;

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
	int	i;
	int	j;
	int	last_char;

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
			while (last_char > 0 && map[i][last_char]
				&& map[i][last_char] == ' ')
				last_char--;
		}
		if (map[i][j] != '1' || map[i][last_char] != '1')
			return (0);
		i++;
	}
	return (1);
}
