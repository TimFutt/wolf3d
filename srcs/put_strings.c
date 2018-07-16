/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_strings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:10:50 by tifuret           #+#    #+#             */
/*   Updated: 2018/07/11 13:10:51 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_put_diff(t_mlx *e)
{
	if (e->diff == 1)
		mlx_string_put(e->mlx, e->win, 10, 5, 0xFFFFFF, "Difficulty : Easy");
	if (e->diff == 2)
		mlx_string_put(e->mlx, e->win, 10, 5, 0xFFFFFF, "Difficulty : Classic");
	if (e->diff == 3)
		mlx_string_put(e->mlx, e->win, 10, 5, 0xFFFFFF,
			"Difficulty : Hardcore");
}

void	ft_put_res(t_mlx *e)
{
	if (e->res == 1)
		mlx_string_put(e->mlx, e->win, 10, 25, 0xFFFFFF,
			"Resolution : 320/180");
	if (e->res == 2)
		mlx_string_put(e->mlx, e->win, 10, 25, 0xFFFFFF,
			"Resolution : 640/360");
	if (e->res == 3)
		mlx_string_put(e->mlx, e->win, 10, 25, 0xFFFFFF,
			"Resolution : 1280/720");
	if (e->res == 4)
		mlx_string_put(e->mlx, e->win, 10, 25, 0xFFFFFF,
			"Resolution : 1920/1080");
	if (e->res == 5)
		mlx_string_put(e->mlx, e->win, 10, 25, 0xFFFFFF,
			"Resolution : 3840/2160");
}

void	ft_put_str(t_mlx *e)
{
	ft_put_diff(e);
	ft_put_res(e);
}
