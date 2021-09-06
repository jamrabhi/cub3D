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

int	get_NO(const char *line, t_map *map)
{
	char	**path;

	path = ft_split(line, ' ');
	if (line && path[0] && (ft_strncmp(path[0], "NO", 2) == 0))
	{
		if (path[2] || map->NO_path)
			print_error("Fichier .cub incorrect");
		map->NO_path = path[1];
		return (1);
	}
	return (0);
}

int	get_SO(const char *line, t_map *map)
{
	char	**path;

	path = ft_split(line, ' ');
	if (line && path[0] && (ft_strncmp(path[0], "SO", 2) == 0))
	{
		if (path[2] || map->SO_path)
			print_error("Fichier .cub incorrect");
		map->SO_path = path[1];
		return (1);
	}
	return (0);
}

int	get_WE(const char *line, t_map *map)
{
	char	**path;

	path = ft_split(line, ' ');
	if (line && path[0] && (ft_strncmp(path[0], "WE", 2) == 0))
	{
		if (path[2] || map->WE_path)
			print_error("Fichier .cub incorrect");
		map->WE_path = path[1];
		return (1);
	}
	return (0);
}

int	get_EA(const char *line, t_map *map)
{
	char	**path;

	path = ft_split(line, ' ');
	if (line && path[0] && (ft_strncmp(path[0], "EA", 2) == 0)) //line pr espace
	{
		if (path[2] || map->EA_path)
			print_error("Fichier .cub incorrect");
		map->EA_path = path[1];
		return (1);
	}
	return (0);
}
