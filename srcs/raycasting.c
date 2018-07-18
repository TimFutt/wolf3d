/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 16:04:41 by chaydont          #+#    #+#             */
/*   Updated: 2018/07/16 15:02:27 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <math.h>

/*typedef struct	s_pov
{
	double	angle;
	double	x;
	double	y;
}				t_pov;*/


void	put_pixel(char *img, int x, int y, int color)
{
	if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT || y < 0 || x < 0)
		return ;
	img[(y * WINDOW_WIDTH + x) * 4] = color % 256;
	img[(y * WINDOW_WIDTH + x) * 4 + 1] = (color / 256) % 256;
	img[(y * WINDOW_WIDTH + x) * 4 + 2] = color / 256 / 256;
}


void	drawColumn(int height, int color, int x, t_mlx mlx)
{
	int y;

	y = -1;
	while (++y < (WINDOW_HEIGHT - height) / 2)
		put_pixel(mlx.str, x, y, 0);
	while (++y < (WINDOW_HEIGHT - height) / 2 + height)
		put_pixel(mlx.str, x, y, color);
	while (++y < WINDOW_HEIGHT)
		put_pixel(mlx.str, x, y, 0);
}

void	ray(/*t_mlx player,*/ int grid[10][10], double angle, int x, t_mlx mlx)
{
	int stepX;
	int stepY;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	int side;
	int color;

	//printf("%f\n", angle);
	rayDirX = cos(angle);
	rayDirY = sin(angle);
	deltaDistX = fabs(1 / rayDirX);
	deltaDistY = fabs(1 / rayDirY);
	mapX = (int)mlx.x;
	mapY = (int)mlx.y;
	if (rayDirX < 0)
	{
		stepX = -1;
		sideDistX = (mlx.x - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (mapX + 1.0 - mlx.x) * deltaDistX;
	}
	if (rayDirY < 0)
	{
		stepY = -1;
		sideDistY = (mlx.y - mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapY + 1.0 - mlx.y) * deltaDistY;
	}
	while (!grid[mapX][mapY] && mapX < 10 && mapX >= 0 && mapY < 10 && mapY >= 0)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 1;
			color = 0xffaa33;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 0;
			color = 0x33aaff;
		}
	}
	double dist;
	if (side)
		dist = (mapX - mlx.x + (1 - stepX) / 2) / rayDirX;
	else
		dist = (mapY - mlx.y + (1 - stepY) / 2) / rayDirY;
	drawColumn((int)(500 / dist), color, x, mlx);
}

void	raycasting(/*t_pov player,*/ int grid[10][10], int fov, t_mlx mlx)
{
	double	gap;
	int		i;

	printf("%f\n", mlx.angle);
	i = -1;
	gap = fov / (double)WINDOW_WIDTH;
	while (++i < WINDOW_WIDTH - 10)
	{
		ray(/*player,*/ grid, (gap * i) + mlx.angle - (fov / 2), i, mlx);
		//usleep(100);
	}
}

int		main()
{
	//t_pov	player;
	t_mlx	mlx;
	int a;
	int b;
	int c;
	int	grid[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
						{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
						{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
						{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
						{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
						{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
						{0, 0, 0, 0, 0, 0, 0, 0, 1, 0}};
	mlx.angle = 2.1;
	mlx.x = 5.7;
	mlx.y = 5.7;
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Wolf3D");
	mlx.img = mlx_new_image(mlx.ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx.str = mlx_get_data_addr(mlx.img, &a, &b, &c);
		raycasting(/*player,*/  grid, PI * 0.8, mlx);
		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
		//ft_keys(&mlx);
	mlx_destroy_image(mlx.ptr, mlx.img);
	mlx_loop(mlx.ptr);
	return (0);
}
