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

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_game_struct(&data);
	load_game_settings(&data, argc, argv);
	if (!(init_game(&data)))
	{
		write(1, "Error\n[MLX]Connection to MLX failed.\n", 37);
		return (0);
	}
	free_map_file(&data);
	return (0);
}
