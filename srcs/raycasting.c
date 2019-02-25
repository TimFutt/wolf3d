/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 15:23:38 by chaydont          #+#    #+#             */
/*   Updated: 2018/11/01 15:10:38 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <math.h>

t_pov	findpoint_x(t_pov p, int **grid, double angle, t_mlx mlx)
{
	t_pov	a;
	int		step;

	step = cos(angle) > 0 ? 1 : -1;
	a.x = cos(angle) > 0 ? (int)p.x : (int)p.x + 1;
	while (1)
	{
		a.x += step;
		a.y = (a.x - p.x) * tan(angle) + p.y;
		if (a.x <= 0 || a.y < 0 || a.x >= mlx.length || a.y > mlx.height
				|| grid[(int)a.y][(int)a.x - (1 - step) / 2])
			return (a);
	}
	return (a);
}

t_pov	findpoint_y(t_pov p, int **grid, double angle, t_mlx mlx)
{
	t_pov	a;
	int		step;

	step = sin(angle) > 0 ? 1 : -1;
	a.y = sin(angle) > 0 ? (int)p.y : (int)p.y + 1;
	while (1)
	{
		a.y += step;
		a.x = (a.y - p.y) / tan(angle) + p.x;
		if (a.x < 0 || a.y <= 0 || a.x > mlx.length || a.y >= mlx.height
				|| grid[(int)a.y - (1 - step) / 2][(int)a.x])
			return (a);
	}
	return (a);
}

void	ray(t_pov p, int **grid, double angle, t_mlx mlx)
{
	t_pov	p_x;
	t_pov	p_y;
	double	dist_x;
	double	dist_y;

	p_x = findpoint_x(p, grid, angle, mlx);
	p_y = findpoint_y(p, grid, angle, mlx);
	dist_x = sqrt((p.x - p_x.x) * (p.x - p_x.x) + (p.y - p_x.y) * (p.y - p_x.y)
			* cos(p.angle - angle));
	dist_y = sqrt((p.x - p_y.x) * (p.x - p_y.x) + (p.y - p_y.y) * (p.y - p_y.y)
			* cos(p.angle - angle));
	if (dist_x > dist_y)
	{
		mlx.side = sin(angle) > 0 ? 1 : 0;
		drawcolumn(dist_y, p_y.x - (int)p_y.x, p.i, mlx);
	}
	else
	{
		mlx.side = cos(angle) > 0 ? 3 : 2;
		drawcolumn(dist_x, p_x.y - (int)p_x.y, p.i, mlx);
	}
}

void	raycasting(t_pov player, int **grid, t_mlx mlx)
{
	double	gap;

	player.i = -1;
	player.fov *= mlx.p.zoom;
	gap = player.fov / (double)WINDOW_WIDTH;
	while (++player.i < WINDOW_WIDTH)
		ray(player, grid, (gap * player.i) + player.angle
		- player.fov / 2, mlx);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
}
