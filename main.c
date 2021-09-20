/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:41:10 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/27 21:44:32 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_map	map;

	ft_bzero(&map, sizeof(map));
	if (argc > 1)
		parse_line(argv[1], &map);
	printf("-------------------------\n_________________________\n");
	printf("INFO DATA STRUCT. :\n");
	printf("NO : '%s'\n", map.no_path);
	printf("SO : '%s'\n", map.so_path);
	printf("WE : '%s'\n", map.we_path);
	printf("EA : '%s'\n", map.ea_path);
	printf("FLOOR : R = '%d', G= '%d', B = '%d'\n", map.f[0], map.f[1], map.f[2]);
	printf("CEILING : R = '%d', G= '%d', B = '%d'\n", map.c[0], map.c[1], map.c[2]);
	printf("SPAWNING ORIENTATION : '%c'\n", map.spawn_dir);
	printf("-------------------------\n_________________________\n");
}
