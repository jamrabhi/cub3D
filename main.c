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
	t_map map;

	ft_bzero(&map, sizeof(map));
	if (argc > 1)
		parse_line(argv[1], &map);

	
	printf("-------------------------\n_________________________\n");
	printf("INFO DATA STRUCT. :\n");
	printf("NO : %s\n", map.NO_path);
	printf("SO : %s\n", map.SO_path);
	printf("WE : %s\n", map.WE_path);
	printf("EA : %s\n", map.EA_path);
	printf("FLOOR : R = %d, G= %d, B = %d\n", map.F[0], map.F[1], map.F[2]);
	printf("CEILING : R = %d, G= %d, B = %d\n", map.C[0], map.C[1], map.C[2]);
	printf("-------------------------\n_________________________\n");


}
