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

int	get_no(char *line, t_data *data)
{
	char	**path;

	if (!data->map->no_path)
	{
		path = ft_split(line, ' ');
		if (line && path[0] && (ft_strcmp(path[0], "NO") == 0))
		{
			if (path[2] || data->map->no_path)
				exit_error_n_free_array_n_line("Misconfiguration in the .cub \
scene (NO texture)", path, line, data);
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
			if (path[2] || data->map->so_path)
				exit_error_n_free_array_n_line("Misconfiguration in the .cub \
scene (SO texture)", path, line, data);
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
			if (path[2] || data->map->we_path)
				exit_error_n_free_array_n_line("Misconfiguration in the .cub \
scene (WE texture)", path, line, data);
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
			if (path[2] || data->map->ea_path)
				exit_error_n_free_array_n_line("Misconfiguration in the .cub \
scene (EA texture)", path, line, data);
			data->map->ea_path = ft_strdup(path[1]);
			free_array(path);
			return (1);
		}
		free_array(path);
	}
	return (0);
}
