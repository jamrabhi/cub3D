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

#include "cub3d.h"

int	get_no(const char *line, t_map *map)
{
	char	**path;

	path = ft_split(line, ' ');
	if (line && path[0] && (ft_strncmp(path[0], "NO", 2) == 0))
	{
		if (path[2] || map->no_path)
			print_error("Misconfiguration in the .cub scene (NO texture)");
		map->no_path = path[1];
		return (1);
	}
	return (0);
}

int	get_so(const char *line, t_map *map)
{
	char	**path;

	path = ft_split(line, ' ');
	if (line && path[0] && (ft_strncmp(path[0], "SO", 2) == 0))
	{
		if (path[2] || map->so_path)
			print_error("Misconfiguration in the .cub scene (SO texture)");
		map->so_path = path[1];
		return (1);
	}
	return (0);
}

int	get_we(const char *line, t_map *map)
{
	char	**path;

	path = ft_split(line, ' ');
	if (line && path[0] && (ft_strncmp(path[0], "WE", 2) == 0))
	{
		if (path[2] || map->we_path)
			print_error("Misconfiguration in the .cub scene (WE texture)");
		map->we_path = path[1];
		return (1);
	}
	return (0);
}

int	get_ea(const char *line, t_map *map)
{
	char	**path;

	path = ft_split(line, ' ');
	if (line && path[0] && (ft_strncmp(path[0], "EA", 2) == 0)) //line pr espace
	{
		if (path[2] || map->ea_path)
			print_error("Misconfiguration in the .cub scene (EA texture)");
		map->ea_path = path[1];
		return (1);
	}
	return (0);
}
