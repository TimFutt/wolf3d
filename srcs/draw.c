/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 16:20:16 by chaydont          #+#    #+#             */
/*   Updated: 2018/11/01 15:45:13 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	put_pixel(char *img, int x, int y, int color)
{
	if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT || y < 0 || x < 0)
		return ;
	img[(y * WINDOW_WIDTH + x) * 4 + 0] = (color >> 0) & 0xff;
	img[(y * WINDOW_WIDTH + x) * 4 + 1] = (color >> 8) & 0xff;
	img[(y * WINDOW_WIDTH + x) * 4 + 2] = (color >> 16) & 0xff;
}

static int	put_texture(char *img, double l, int h, t_tex tex)
{
	int a;
	int b;
	int i;

	b = l * tex.sizeline / 4;
	i = 0;
	if (tex.y < 0)
		i = (tex.y + h) / h;
	while (i < h)
	{
		if (i + tex.y >= 0 && i + tex.y < WINDOW_HEIGHT)
		{
			a = i / (double)h * tex.sizeline / 4;
			img[((tex.y + i) * WINDOW_WIDTH + tex.x) * 4 + 0] =
				tex.data[a * tex.sizeline + b * 4 + 0];
			img[((tex.y + i) * WINDOW_WIDTH + tex.x) * 4 + 1] =
				tex.data[a * tex.sizeline + b * 4 + 1];
			img[((tex.y + i) * WINDOW_WIDTH + tex.x) * 4 + 2] =
				tex.data[a * tex.sizeline + b * 4 + 2];
			img[((tex.y + i) * WINDOW_WIDTH + tex.x) * 4 + 3] =
				tex.data[a * tex.sizeline + b * 4 + 3];
		}
		i++;
	}
	return (i);
}

void		drawcolumn(double dist, double l, int x, t_mlx mlx)
{
	int		y;
	int		height;
	t_tex	tex;

	y = 0;
	tex = mlx.tex[mlx.side];
	height = WINDOW_HEIGHT / dist / mlx.p.zoom;
	while (y - mlx.p.head < (WINDOW_HEIGHT - height) / 2)
		put_pixel(mlx.str, x, y++, 0x33aaff);
	if (y == 0)
		y = (WINDOW_HEIGHT - height) / 2 + mlx.p.head;
	tex.x = x;
	tex.y = y;
	y += put_texture(mlx.str, l, height, tex);
	while (y < WINDOW_HEIGHT)
		put_pixel(mlx.str, x, y++, 0x333333);
}
