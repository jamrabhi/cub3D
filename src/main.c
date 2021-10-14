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

#include <cub3d.h>

t_map	g_map;
int		g_fd;

int	main(int argc, char **argv)
{
	if (argc != 2)
		print_error(".cub file not specified");
	g_fd = open(argv[1], O_RDONLY);
	if (g_fd == -1)
		print_error("File doesn't exist");
	ft_bzero(&g_map, sizeof(g_map));
	parse_line(argv[1]);
	
	printf("-------------------------\n_________________________\n");
	printf("INFO DATA STRUCT. :\n");
	printf("NO : '%s'\n", g_map.no_path);
	printf("SO : '%s'\n", g_map.so_path);
	printf("WE : '%s'\n", g_map.we_path);
	printf("EA : '%s'\n", g_map.ea_path);
	printf("FLOOR : R = '%d', G= '%d', B = '%d'\n", g_map.f[0], g_map.f[1], g_map.f[2]);
	printf("CEILING : R = '%d', G= '%d', B = '%d'\n", g_map.c[0], g_map.c[1], g_map.c[2]);
	printf("SPAWNING ORIENTATION : '%c'\n", g_map.spawn_dir);
	printf("-------------------------\n_________________________\n");
	free(g_map.no_path);
	free(g_map.so_path);
	free(g_map.we_path);
	free(g_map.ea_path);
}
