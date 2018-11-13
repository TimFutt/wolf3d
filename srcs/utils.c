/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:29:16 by tifuret           #+#    #+#             */
/*   Updated: 2018/11/01 16:11:30 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		ft_events(int keycode, t_mlx *mlx)
{
	ft_keys_moove(keycode, mlx);
	ft_keys_moove2(keycode, mlx);
	if (keycode == EXIT)
		exit(0);
	return (0);
}

void	ft_keys(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 0, ft_events, mlx);
	mlx_hook(mlx->win, 6, (1L << 6), ft_mouse_pos, mlx);
	mlx_hook(mlx->win, 17, (1L << 0), hook_close, mlx);
	mlx_hook(mlx->win, (1 << 2), 0, mouse_button, mlx);
}

void	usage(void)
{
	ft_putendl("Usage: ./wolf3d [Map]");
	ft_putendl("       ./wolf3d -menu [Map]");
}
