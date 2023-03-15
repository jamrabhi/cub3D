/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:05:23 by dsy               #+#    #+#             */
/*   Updated: 2020/07/08 01:22:50 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_data(t_game *data)
{
	data->pos_x = 0;
	data->pos_y = 0;
	data->dirX = 0;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = 0;
	//data->map = 0;
	data->so.mlx_img = 0;
	data->no.mlx_img = 0;
	data->ea.mlx_img = 0;
	data->we.mlx_img = 0;
	data->floor.set = 0;
	data->ceiling.set = 0;
	//data->sprite.ptr = 0;
	//data->valid = 1;
	//data->save = 0;
	//data->weapon.ptr = 0;
	//data->speed = 1;
	//data->life = 1;
	return (1);
}

int	init_game(t_game *data)
{
	init_game_struct(data);
	init_data(data);
	data->width = ft_atoi(data->r_key[1]);
	data->height = ft_atoi(data->r_key[2]);
	data->floor.R = ft_atoi(data->f_key[0]);
	data->floor.G = ft_atoi(data->f_key[1]);
	data->floor.B = ft_atoi(data->f_key[2]);
	data->ceiling.R = ft_atoi(data->r_key[0]);
	data->ceiling.G = ft_atoi(data->r_key[1]);
	data->ceiling.B = ft_atoi(data->r_key[2]);
	// if (!(get_player_data(data)))
	// 	return (0);
	if (!(data->mlx_ptr = mlx_init()))
		return (0);
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr, data->width, data->height, "Cub3D")))
		return (0);
	mlx_hook(data->win_ptr, 2, 0, key_stroke, data);
	mlx_hook(data->win_ptr, 17, 0, cross_window, data);
	//mlx_loop_hook(data->mlx_ptr, raycasting, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
