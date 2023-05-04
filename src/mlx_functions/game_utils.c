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

void	set_player_direction(t_data *d)
{
	if (d->player_orientation == 'S')
		d->player_dir = PI / 2;
	else if (d->player_orientation == 'N')
		d->player_dir = -PI / 2;
	else if (d->player_orientation == 'W')
		d->player_dir = PI;
	else if (d->player_orientation == 'E')
		d->player_dir = 0;
	else
		return ;
}

void	player_spawn(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->map_arr[i])
	{
		j = 0;
		while (data->map_arr[i][j])
		{
			if (data->map_arr[i][j] == 'N' || data->map_arr[i][j] == 'S' || \
				data->map_arr[i][j] == 'W' || data->map_arr[i][j] == 'E')
			{
				data->player_x = i + 0.5;
				data->player_y = j + 0.5;
				data->player_orientation = data->map_arr[i][j];
				set_player_direction(data);
				data->map_arr[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
