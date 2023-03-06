/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:45:27 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/27 23:29:25 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	check_xpm(char *file_name)
{
	const char	*dot;

	dot = NULL;
	if (file_name)
	{
		dot = ft_strrchr(file_name, '.');
		if (!dot || ft_strncmp(dot, ".xpm", 5) != 0 || ft_strlen(file_name) < 5)
			return (0);
		else
			return (1);
	}
	return (0);
}

int	get_no(char *line, t_data *data)
{
	char	**path;

	if (!data->map->no_path)
	{
		path = ft_split(line, ' ');
		if (line && path[0] && (ft_strcmp(path[0], "NO") == 0))
		{
			if (!path[1] || path[2] || data->map->no_path
				|| !check_xpm(path[1]))
				exit_error_n_free_array_n_line(MISCONF_NO, path, line, data);
			data->map->no_path = ft_strdup(path[1]);
			free_array(path);
			return (1);
		}
		free_array(path);
	}
	return (0);
}

int	get_so(char *line, t_data *data)
{
	char	**path;

	if (!data->map->so_path)
	{
		path = ft_split(line, ' ');
		if (line && path[0] && (ft_strcmp(path[0], "SO") == 0))
		{
			if (!path[1] || path[2] || data->map->so_path
				|| !check_xpm(path[1]))
				exit_error_n_free_array_n_line(MISCONF_SO, path, line, data);
			data->map->so_path = ft_strdup(path[1]);
			free_array(path);
			return (1);
		}
		free_array(path);
	}
	return (0);
}

int	get_we(char *line, t_data *data)
{
	char	**path;

	if (!data->map->we_path)
	{
		path = ft_split(line, ' ');
		if (line && path[0] && (ft_strcmp(path[0], "WE") == 0))
		{
			if (!path[1] || path[2] || data->map->we_path
				|| !check_xpm(path[1]))
				exit_error_n_free_array_n_line(MISCONF_WE, path, line, data);
			data->map->we_path = ft_strdup(path[1]);
			free_array(path);
			return (1);
		}
		free_array(path);
	}
	return (0);
}

int	get_ea(char *line, t_data *data)
{
	char	**path;

	if (!data->map->ea_path)
	{
		path = ft_split(line, ' ');
		if (line && path[0] && (ft_strcmp(path[0], "EA") == 0))
		{
			if (!path[1] || path[2] || data->map->ea_path
				|| !check_xpm(path[1]))
				exit_error_n_free_array_n_line(MISCONF_EA, path, line, data);
			data->map->ea_path = ft_strdup(path[1]);
			free_array(path);
			return (1);
		}
		free_array(path);
	}
	return (0);
}
