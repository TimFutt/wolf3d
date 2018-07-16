/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:10:39 by tifuret           #+#    #+#             */
/*   Updated: 2018/07/11 13:10:40 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	menu(t_mlx *e)
{
	int		i;

	if (e->win)
	{
		mlx_destroy_window(e->mlx, e->win);
		e->win = NULL;
	}
	if (e->choice == 1)
	{
		e->win = mlx_new_window(e->mlx, 1024, 768, "WOLF3D");
		e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/START.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
		mlx_key_hook(e->win, key_hook_menu, e);
	}
	else if (e->choice == 2 || e->choice == 3)
		menu2(e);
	else if (e->choice == 4 || e->choice == 5)
		menu3(e);
}

void	menu2(t_mlx *e)
{
	int		i;

	if (e->choice == 2)
	{
		e->win = mlx_new_window(e->mlx, 1024, 768, "Menu");
		e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/MENU.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
		ft_put_str(e);
		mlx_key_hook(e->win, key_hook_menu, e);
		mlx_hook(e->win, 4, (1L << 2), mouse_clic_menu, e);
		mlx_hook(e->win, 5, (1L << 2), mouse_release_menu, e);
		mlx_hook(e->win, 6, (1L << 6), mouse_motion_menu, e);
	}
	else if (e->choice == 3)
	{
		e->win = mlx_new_window(e->mlx, 1024, 768, "Settings");
		e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/SETTINGS.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
		ft_put_str(e);
		mlx_key_hook(e->win, key_hook_settings, e);
		mlx_hook(e->win, 4, (1L << 2), mouse_clic_settings, e);
		mlx_hook(e->win, 5, (1L << 2), mouse_release_settings, e);
		mlx_hook(e->win, 6, (1L << 6), mouse_motion_settings, e);
	}
}

void	menu3(t_mlx *e)
{
	int		i;

	if (e->choice == 4)
	{
		e->win = mlx_new_window(e->mlx, 1024, 768, "Difficulty");
		e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/DIFF.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
		ft_put_str(e);
		mlx_key_hook(e->win, key_hook_difficulty, e);
		mlx_hook(e->win, 4, (1L << 2), mouse_clic_difficulty, e);
		mlx_hook(e->win, 5, (1L << 2), mouse_release_difficulty, e);
		mlx_hook(e->win, 6, (1L << 6), mouse_motion_difficulty, e);
	}
	else if (e->choice == 5)
	{
		e->win = mlx_new_window(e->mlx, 1024, 768, "Resolution");
		e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/RESO.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
		ft_put_str(e);
		mlx_key_hook(e->win, key_hook_resolution, e);
		mlx_hook(e->win, 4, (1L << 2), mouse_clic_resolution, e);
		mlx_hook(e->win, 5, (1L << 2), mouse_release_resolution, e);
		mlx_hook(e->win, 6, (1L << 6), mouse_motion_resolution, e);
	}
}
