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

#include <cub3D.h>

void	check_cub(char *file_name, t_data *data)
{
	const char	*dot;

	dot = ft_strrchr(file_name, '.');
	if (ft_strncmp(dot, ".cub", 5) != 0)
		exit_error(INVALID_FILE, data);
}

int	check_elements(t_data *data)
{
	if (data->map->no_path && data->map->so_path && data->map->ea_path
		&& data->map->we_path && data->map->f[0] > -1 && data->map->c[0] > -1)
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

void	parse_line(char *file_cub, t_data *data)
{
	char	*line;
	int		ret;

	ret = 1;
	check_cub(file_cub, data);
	data->map->f[0] = -1;
	data->map->c[0] = -1;
	while (ret && check_elements(data) == 0)
	{
		ret = get_next_line(data->map_fd, &line);
		if ((!(get_no(line, data) || get_so(line, data) || get_we(line, data)
					|| get_ea(line, data) || get_f_c_rgb(line, 'F', data)
					|| get_f_c_rgb(line, 'C', data)))
			&& !check_empty_line(line))
			exit_error_n_free_line(INVALID_ELEM, line, data);
		free(line);
	}
	if (!check_elements(data))
		exit_error(MISSING_ELEM, data);
	parse_map(line, data);
	close(data->map_fd);
}
