/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:54:47 by tifuret           #+#    #+#             */
/*   Updated: 2018/11/01 16:11:15 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		ft_keys_moove(int keycode, t_mlx *mlx)
{
	double newx;
	double newy;

	newx = mlx->p.x;
	newy = mlx->p.y;
	if (keycode == RIGHT || keycode == 2)
	{
		newx -= 0.2 * cos(mlx->p.angle - PI / 2);
		newy -= 0.2 * sin(mlx->p.angle - PI / 2);
	}
	else if (keycode == LEFT || keycode == 0)
	{
		newx -= 0.2 * cos(mlx->p.angle + PI / 2);
		newy -= 0.2 * sin(mlx->p.angle + PI / 2);
	}
	if (newx < 0.1 || newx > mlx->length - 0.1 || newy < 0.1
			|| newy > mlx->height - 0.1 || mlx->map[(int)newy][(int)newx])
		return (0);
	mlx->p.x = newx;
	mlx->p.y = newy;
	raycasting(mlx->p, mlx->map, *mlx);
	return (0);
}

int		ft_keys_moove2(int keycode, t_mlx *mlx)
{
	double newx;
	double newy;

	newx = mlx->p.x;
	newy = mlx->p.y;
	if (keycode == UP || keycode == 13)
	{
		newx += 0.2 * cos(mlx->p.angle);
		newy += 0.2 * sin(mlx->p.angle);
	}
	else if (keycode == DOWN || keycode == 1)
	{
		newx -= 0.2 * cos(mlx->p.angle);
		newy -= 0.2 * sin(mlx->p.angle);
	}
	if (newx < 0.1 || newx > mlx->length - 0.1 || newy < 0.1
			|| newy > mlx->height - 0.1 || mlx->map[(int)newy][(int)newx])
		return (0);
	mlx->p.x = newx;
	mlx->p.y = newy;
	raycasting(mlx->p, mlx->map, *mlx);
	return (0);
}

int		ft_mouse_pos(int x, int y, t_mlx *mlx)
{
	mlx->p.angle -= (double)((mlx->ox - x) / 100.);
	mlx->ox = x;
	mlx->p.head = -(2 * y) + WINDOW_HEIGHT;
	raycasting(mlx->p, mlx->map, *mlx);
	return (0);
}

int		mouse_button(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == 5 && mlx->p.zoom < 1.2)
		mlx->p.zoom *= 1.2;
	else if (button == 4 && mlx->p.zoom > 0.4)
		mlx->p.zoom /= 1.2;
	else if (button == 3)
		mlx->p.zoom = 1;
	raycasting(mlx->p, mlx->map, *mlx);
	return (0);
}

int		hook_close(t_mlx *mlx)
{
	(void)*mlx;
	exit(0);
	return (0);
}
