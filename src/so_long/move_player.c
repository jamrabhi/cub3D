/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:05:57 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/05/05 21:06:02 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	move_player(t_data *data, int to_x, int to_y)
{
	if (data->map[to_y][to_x] != WALL)
	{
			data->map[data->player_pos_y][data->player_pos_x] = EMPTY;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->empty_img, data->player_pos_x * 50,
				data->player_pos_y * 50);
			data->map[to_y][to_x] = PLAYER;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player_img, to_x * 50, to_y * 50);
			data->player_pos_x = to_x;
			data->player_pos_y = to_y;
			ft_putnbr_fd(++data->move_count, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
	}
}
