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

void	draw_ray(t_data *data)
{
	int rwidth = data->resolution / data->map_width;

	data->ray.ra = data->pos_ang;
	data->ray.dof = 0;
	float aTan = -1/tan(data->ray.ra);
	if (data->ray.ra > PI)
	{
		int calc = data->pos_y / rwidth;
		calc *= rwidth;
		data->ray.ry = calc - 0.0001;
		data->ray.rx = (data->pos_y - data->ray.ry) * aTan + data->pos_x;
		data->ray.yo = -rwidth;
		data->ray.xo = - data->ray.yo * aTan;
	}
	if (data->ray.ra < PI)
	{
		int calc = data->pos_y / rwidth;
		calc *= rwidth;
		data->ray.ry = calc + rwidth;
		data->ray.rx = (data->pos_y - data->ray.ry) * aTan + data->pos_x;
		data->ray.yo = rwidth;
		data->ray.xo = - data->ray.yo * aTan;
	}
	if (data->ray.ra == 0 || data->ray.ra == PI)
	{
		data->ray.rx = data->pos_x;
		data->ray.ry = data->pos_y;
		data->ray.dof = 8;
	}
	while (data->ray.dof < 8)
	{
		data->ray.mx = (int)(data->ray.rx / (float)rwidth);
		data->ray.my = (int)(data->ray.ry / (float)rwidth);
		if ((data->ray.mx < data->map_height-1 && data->ray.mx >= 0) 
        && (data->ray.my < data->map_width-1 && data->ray.my >= 0))
		{
			if (data->ray.my <= 0)
				data->ray.my = 1;
			if (data->ray.mx <= 0)
				data->ray.mx = 1;
            if (data->ray.my >= data->map_height)
				data->ray.my = data->map_height - 1;
			if (data->ray.mx >= data->map_width)
				data->ray.mx = data->map_width - 1;
		printf("rx ry mx my %i %i %i %i\n",  data->ray.mx,  data->ray.mx, data->ray.mx, data->ray.my);
			if (data->map_arr[data->ray.mx - 1][data->ray.my - 1] \
            && data->map_arr[data->ray.mx -1][data->ray.my -1] == '1')
				data->ray.dof = 8;
			else
				data->ray.dof++;
		}
		else
		{
			data->ray.rx += data->ray.xo;
			data->ray.ry += data->ray.yo;
			data->ray.dof++;
		}
	}

    data->ray.dof = 0;
	float nTan = -tan(data->ray.ra);
	if (data->ray.ra > P2 && data->ray.ra < P3)
	{
		int calc = data->pos_y / rwidth;
		calc *= rwidth;
		data->ray.rx = calc - 0.0001;
		data->ray.ry = (data->pos_x - data->ray.rx) * nTan + data->pos_y;
		data->ray.xo = -rwidth;
		data->ray.yo = - data->ray.xo * nTan;
	}
	if (data->ray.ra < P2 || data->ray.ra > P3)
	{
		int calc = data->pos_y / rwidth;
		calc *= rwidth;
		data->ray.rx = calc + rwidth;
		data->ray.ry = (data->pos_x - data->ray.rx) * nTan + data->pos_y;
		data->ray.xo = rwidth;
		data->ray.yo = - data->ray.xo * nTan;
	}
	if (data->ray.ra == 0 || data->ray.ra == PI)
	{
		data->ray.rx = data->pos_x;
		data->ray.ry = data->pos_y;
		data->ray.dof = 8;
	}
	while (data->ray.dof < 8)
	{
		data->ray.mx = (int)(data->ray.rx / (float)rwidth);
		data->ray.my = (int)(data->ray.ry / (float)rwidth);
		if ((data->ray.mx < data->map_height-1 && data->ray.mx > 0) 
        && (data->ray.my < data->map_width-1 && data->ray.my > 0))
		{
			if (data->ray.my <= 0)
			{
                printf("correcting MY<0 : %i\n", data->ray.my);
                data->ray.my = 1;
            }
            if (data->ray.mx <= 0)
            {
                printf("correcting MX<0 : %i\n", data->ray.mx);    
				data->ray.mx = 1;
            }
            if (data->ray.my >= data->map_height -1)
            {
                printf("correcting MX>m : %i\n", data->ray.my);
				data->ray.my = data->map_height - 2;
            }
            if (data->ray.mx >= data->map_width -1)
            {
                printf("correcting MX>m : %i\n", data->ray.mx);
				data->ray.mx = data->map_width - 2;
            }
		printf("rx ry mx my %i %i %i %i\n",  data->ray.mx,  data->ray.mx, data->ray.mx, data->ray.my);
			if (data->map_arr[data->ray.mx - 1][data->ray.my - 1] \
            && data->map_arr[data->ray.mx -1][data->ray.my -1] == '1')
				data->ray.dof = 8;
			else
				data->ray.dof++;
		}
		else
		{
			data->ray.rx += data->ray.xo;
			data->ray.ry += data->ray.yo;
			data->ray.dof += 1;
		}
	}

    data->ray.color = 0xFFFFFF;
	draw_line(data->pos_x + 5, data->pos_y + 5, data->ray.rx, data->ray.ry, data);
}