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

#include <cub3D.h>

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
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

char	*get_array(char *line, t_data *data)
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	int		ret;

	str = ft_strdup("");
	ret = 1;
	while (ret)
	{
		ret = get_next_line(data->map_fd, &line);
		if (ret < 0)
			exit_error("Invalid map", data);
		tmp = ft_strjoin(line, "\n");
		tmp2 = ft_strjoin(str, tmp);
		free(str);
		str = ft_strdup(tmp2);
		free(line);
		free(tmp);
		free(tmp2);
	}
	close(data->map_fd);
	return (str);
}

void	parse_map(char *line, t_data *data)
{
	char	*map_str;
	char	**map_array;

	map_str = get_array(line, data);
	if (!map_str)
		exit_error("Invalid map", data);
	map_array = ft_split(map_str, '\n');
	if (!(check_valid_map(map_str, data) && check_first_line(map_array)
			&& check_last_line(map_array) && check_borders(map_array)
			&& check_map(map_array)))
	{
		free(map_str);
		free_split(map_array);
		exit_error("Invalid map", data);
	}
	data->map_arr = map_array;
	free(map_str);
}
