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

	static void handle_keys(t_data *data)
	{
		// // Handle key presses
		if (data->turn_left) {
			data->playerDir -= 0.1 * ROT_SPEED;
			data->turn_left = 0;
		}
		if (data->turn_right) {
			data->playerDir += 0.1 * ROT_SPEED;
			data->turn_right = 0;
		}
		double playerVelX = cos(data->playerDir) * MOVE_SPEED;
		double playerVelY = sin(data->playerDir) * MOVE_SPEED;
		if (data->move_up) {
			double nextPlayerX = data->playerX + playerVelX;
			double nextPlayerY = data->playerY + playerVelY;
			int nextMapX = (int)nextPlayerX;
			int nextMapY = (int)nextPlayerY;
			if (data->map_arr[nextMapX][nextMapY] == '0') {
				data->playerX = nextPlayerX;
				data->playerY = nextPlayerY;
			}
			data->move_up = 0;
		}
		if (data->move_down) {
			double nextPlayerX = data->playerX - playerVelX;
			double nextPlayerY = data->playerY - playerVelY;
			int nextMapX = (int)nextPlayerX;
			int nextMapY = (int)nextPlayerY;
			if (data->map_arr[nextMapX][nextMapY] == '0') {
				data->playerX = nextPlayerX;
				data->playerY = nextPlayerY;
			}
			data->move_down = 0;
		}
		if (data->playerDir < 0) {
			data->playerDir += 2 * M_PI;
		} else if (data->playerDir >= 2 * M_PI) {
			data->playerDir -= 2 * M_PI;
		}
	}

	void draw_walls(t_data *data)
	{
		// Render loop
		// while (1) {
			
		// Clear the buffer	
		memset(data->buffer[data->current_buffer]->addr, 0, data->buffer[data->current_buffer]->sl * SCREENSIZE);
		handle_keys(data);
		// Render the walls
		for (int x = 0; x < SCREENSIZE; x++) 
		{	
			for (int i = 0; i < 5; i++) {
				double cameraX = 2 * x / (double)SCREENSIZE - 1; // center on screen and normalize
				double rayDirX = cos(data->playerDir + data->fov * cameraX);
				double rayDirY = sin(data->playerDir + data->fov * cameraX);
				int mapX = (int)data->playerX;
				int mapY = (int)data->playerY;
				double sideDistX, sideDistY;
				if (rayDirX == 0)
					rayDirX = 1;
				if (rayDirY == 0)
					rayDirY = 1;
				double deltaDistX = fabs(1 / rayDirX);
				double deltaDistY = fabs(1 / rayDirY);
				int stepX, stepY;
				int hit = 0;
				int side;

				if (rayDirX < 0) {
					stepX = -1;
					sideDistX = (data->playerX - mapX) * deltaDistX;
				} else {
					stepX = 1;
					sideDistX = (mapX + 1.0 - data->playerX) * deltaDistX;
				}
				if (rayDirY < 0) {
					stepY = -1;
					sideDistY = (data->playerY - mapY) * deltaDistY;
				} else {
					stepY = 1;
					sideDistY = (mapY + 1.0 - data->playerY) * deltaDistY;
				}
				while (!hit) {
					if (sideDistX < sideDistY) {
						sideDistX += deltaDistX;
						mapX += stepX;
						side = 0;
					} else {
						sideDistY += deltaDistY;
						mapY += stepY;
						side = 1;
					}
					if (data->map_arr[mapX][mapY] == '1')
						hit = 1;
				}
				double perpWallDist;
				if (side == 0)
					perpWallDist = fabs((mapX - data->playerX + (1 - stepX) / 2) / rayDirX);
				else
					perpWallDist = fabs((mapY - data->playerY + (1 - stepY) / 2) / rayDirY);
	double distToWall = perpWallDist * cos((data->playerDir - (data->playerDir + cameraX * data->fov)) * M_PI / 180.0);
				int wall_height = (int)(SCREENSIZE / (distToWall * cos(cameraX * data->fov)));
				int draw_start = SCREENSIZE / 2 - wall_height / 2;
				if (draw_start < 0)
					draw_start = 0;
				int draw_end = wall_height / 2 + SCREENSIZE / 2;
				if (draw_end >= SCREENSIZE)
					draw_end = SCREENSIZE - 1;
				// Calculate the shaded color for the wall
				int wallColor = 0xFF00FF;
				for (int y = 0; y < SCREENSIZE; y++) {
					if (y < draw_start)
						data->buffer[data->current_buffer]->addr[y * SCREENSIZE + x] = data->ceiling_color;
					else if (y > draw_end)
						data->buffer[data->current_buffer]->addr[y * SCREENSIZE + x] = data->floor_color;
					else
						data->buffer[data->current_buffer]->addr[y * SCREENSIZE + x] = wallColor;
				}
			}
			}
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->buffer[data->current_buffer]->img, 0, 0);
			data->current_buffer = (data->current_buffer + 1) % 2;
	}
