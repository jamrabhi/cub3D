/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:35:17 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/02/23 19:35:20 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include "mlx.h"

double	get_wall_position(t_data *d, int side)
{
	double	wall_x;

	if (side == 0)
		wall_x = d->player_y + d->perpwall_dist * d->ray_dir_y;
	else
		wall_x = d->player_x + d->perpwall_dist * d->ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int	get_tex_color(t_data *d, int side, int y, int i)
{
	char	*color;
	double	tex_y;
	double	tex_x;
	double	wall_x;

	wall_x = get_wall_position(d, side);
	tex_y = (y * 2 - SCREENSIZE + d->wall_height) * \
		(d->tex[i].height / 2) / d->wall_height;
	tex_x = (int)(wall_x * d->tex[i].width);
	if ((side == 0 && d->ray_dir_x > 0) || (side == 1 && \
		d->ray_dir_y < 0))
		tex_x = d->tex[i].width - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	else if (tex_x >= d->tex[i].width)
		tex_x = d->tex[i].width - 1;
	if (tex_y < 0)
		tex_y = 0;
	else if (tex_y >= d->tex[i].height)
		tex_y = d->tex[i].height - 1;
	color = d->tex[i].addr + ((int)tex_y * d->tex[i].line_length + \
		(int)tex_x * (d->tex[i].bpp / 8));
	return (*(unsigned int *)color);
}
