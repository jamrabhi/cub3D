/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:33:00 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/12 21:40:45 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>

void	print_error(char *error)
{
	printf("Erreur : %s", error);
	exit (1);
}

void	get_NO(const char *line)
{
	char **path;

	if (line[0] == 'N' && line[1] == 'O')
	{
		path = ft_split(line, ' ');
		printf("%s", path[1]);
	}
	if (path[2])
		print_error("Fichier .cub incorrect");
}

void	parse_line(char **file_cub)
{
	char *line;
	int fd;

	fd = open(*file_cub, O_RDONLY);

	get_next_line(fd, &line);
	printf("%s\n", line);
	get_NO (line);
	printf("KO");
}


