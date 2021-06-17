/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:33:00 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/14 19:52:20 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *error)
{
	printf("Erreur : %s", error);
	exit (1);
}

void	get_NO(const char *line, t_map *map)
{
	char	**path;

//	path = NULL;
	path = ft_split(line, ' ');
	printf("line = %s\n", line);
	if (line && (ft_strncmp(path[0], "NO", 2) == 0))
	{

	printf("NO : %s\n", map->NO_path);
	//	path = ft_split(line, ' ');
		map->NO_path = path[1];
		if (path[2])
			print_error("Fichier .cub incorrect");
	}
}

void	get_SO(const char *line, t_map *map)
{
	char	**path;

	path = NULL;
	if (line[0] == 'S' && line[1] == 'O')
	{
		path = ft_split(line, ' ');
		map->SO_path = path[1];
		if (path[2])
			print_error("Fichier .cub incorrect");
	}
}

void	get_WE(const char *line, t_map *map)
{
	char	**path;

	path = NULL;
	if (line[0] == 'W' && line[1] == 'E')
	{
		path = ft_split(line, ' ');
		map->WE_path = path[1];
		if (path[2])
			print_error("Fichier .cub incorrect");
	}
}

void	get_EA(const char *line, t_map *map)
{
	char	**path;

	path = NULL;
	if (line[0] == 'E' && line[1] == 'A')
	{
		path = ft_split(line, ' ');
		map->EA_path = path[1];
		if (path[2])
			print_error("Fichier .cub incorrect");
	}
}
/*
void	get_F(const char *line, t_map *map)
{
	
*/
void display(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("[%s]\n", tab[i]);
		i += 1;
	}
}
int	parse_line(char *av, t_map *map)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	// char	*leak;
	int		ret;
	int		fd;
	char	**tab;
	

	(void)map;
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n");
		return (-1);
	}
	tmp = ft_strdup("");
	while (1)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = 0;
		// leak = tmp;
		tmp = ft_strjoin(tmp, buff);
		if (ret == 0)
			break ;
	}
	tab = ft_split(tmp, '\n');
	display(tab);
	return (0);
}
