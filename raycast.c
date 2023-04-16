#include "mlx.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define WIDTH 640
#define HEIGHT 480

double map[WIDTH][HEIGHT] = {
	{1, 1, 1, 1, 1},
	{1, 0, 0, 1, 1},
	{1, 0, 1, 1, 1},
	{1, 0, 0, 1, 1},
	{1, 1, 1, 1, 1}
};

int exitb()
{
	exit(1);
}

int turn_left = 0;
int turn_right = 0;

// Function declarations
int key_pressed(int keycode);
int key_released(int keycode);

int main() {
	// Initialize MLX
	void *mlx = mlx_init();
	void *window = mlx_new_window(mlx, WIDTH, HEIGHT, "Raycaster");
	void *image = mlx_new_image(mlx, WIDTH, HEIGHT);
	int bits_per_pixel, size_line, endian;
	char *buffer = mlx_get_data_addr(image, &bits_per_pixel, &size_line, &endian);

	// Initialize raycasting variables
	double playerX = 2.5;
	double playerY = 2.5;
	double playerDir = 0;
	double planeX = 0;
	double planeY = 0.66;


	// Render loop
	while (1) {
		// Clear the buffer	
		memset(buffer, 0, size_line * HEIGHT);

		// Handle key presses
		if (turn_left) {
			playerDir -= 0.1;
		}
		if (turn_right) {
			playerDir += 0.1;
		}

		// Render the walls
		for (int x = 0; x < WIDTH; x++) {
			double cameraX = 2 * x / (double)WIDTH - 1;
			double rayDirX = cos(playerDir) + planeX * cameraX;
			double rayDirY = sin(playerDir) + planeY * cameraX;

			int mapX = (int)playerX;
			int mapY = (int)playerY;

			double sideDistX, sideDistY;
			double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
			double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
			int stepX, stepY;
			int hit = 0;
			int side;

			if (rayDirX < 0) {
				stepX = -1;
				sideDistX = (playerX - mapX) * deltaDistX;
			} else {
				stepX = 1;
				sideDistX = (mapX + 1.0 - playerX) * deltaDistX;
			}
			if (rayDirY < 0) {
				stepY = -1;
				sideDistY = (playerY - mapY) * deltaDistY;
			} else {
				stepY = 1;
				sideDistY = (mapY + 1.0 - playerY);

			}

			while (!hit) {
				if (sideDistX < sideDistY) {
					sideDistX += deltaDistX;
					mapX +=
						stepX;
					side = 0;
				} else {
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				if (map[mapX][mapY]) {
					hit = 1;
				}
			}
			double perpWallDist;
			if (side == 0) {
				perpWallDist = (mapX - data->playerX + (1 - stepX) / 2) / rayDirX;
			} else {
				perpWallDist = (mapY - data->playerY + (1 - stepY) / 2) / rayDirY;
			}


			int lineHeight = abs((int)(HEIGHT / perpWallDist));

			int drawStart = -lineHeight / 2 + HEIGHT / 2;
			if (drawStart < 0) {
				drawStart = 0;
			}
			int drawEnd = lineHeight / 2 + HEIGHT / 2;
			if (drawEnd >= HEIGHT) {
				drawEnd = HEIGHT - 1;
			}

			int color;
			if (side == 0) {
				color = 0xFF0000;
			} else {
				color = 0x00FF00;
			}

			for (int y = drawStart; y <= drawEnd; y++) {
				int pixelIndex = (x * (bits_per_pixel / 8)) + (y * size_line);
				*(int*)(buffer + pixelIndex) = color;
			}

		}

		// Update the window
		mlx_put_image_to_window(mlx, window, image, 0, 0);
		mlx_hook(window, 2, 1L<<0, &key_pressed, 0);
		mlx_hook(window, 3, 1L<<1, &key_released, 0);
		mlx_hook(window, 17, 0L, exitb, 0);
		mlx_loop(mlx);
	}

	return 0;
}

// Handle key presses
int key_pressed(int keycode) {
	if (keycode == 123) {
		turn_left = 1;
	} else if (keycode == 124) {
		turn_right = 1;
	}
    printf("%i\n", keycode);
	return 0;
}

// Handle key releases
int key_released(int keycode) {
	if (keycode == 123) {
		turn_left = 0;
	} else if (keycode == 124) {
		turn_right = 0;
	}
        printf("%i\n", keycode);
	return 0;
}
