/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:11:01 by tifuret           #+#    #+#             */
/*   Updated: 2018/07/11 13:11:02 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		mouse_clic_settings(int b, int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 3)
	{
		mlx_destroy_image(e->ptr, e->data);
		if ((b == 1) && x >= 303 && x <= 708 && y >= 311 && y <= 365)
			e->data = mlx_xpm_file_to_image(e->ptr, DIFFCLIC, &i, &i);
		else if ((b == 1) && x >= 331 && x <= 683 && y >= 499 && y <= 554)
			e->data = mlx_xpm_file_to_image(e->ptr, GRACLIC, &i, &i);
		else if ((b == 1) && x >= 47 && x <= 218 && y >= 702 && y <= 735)
			e->data = mlx_xpm_file_to_image(e->ptr, RCLIC, &i, &i);
		else
			e->data = mlx_xpm_file_to_image(e->ptr, SETTINGS, &i, &i);
		mlx_put_image_to_window(e->ptr, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	return (SUCCESS);
}

int		mouse_release_settings(int b, int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 3)
	{
		mlx_destroy_image(e->ptr, e->data);
		if ((b == 1) && x >= 303 && x <= 708 && y >= 311 && y <= 365)
		{
			e->data = mlx_xpm_file_to_image(e->ptr, DIFFSUR, &i, &i);
			e->choice = 4;
		}
		else if ((b == 1) && x >= 331 && x <= 683 && y >= 499 && y <= 554)
		{
			e->data = mlx_xpm_file_to_image(e->ptr, GRASUR, &i, &i);
			e->choice = 5;
		}
		else
			e->data = mlx_xpm_file_to_image(e->ptr, SETTINGS, &i, &i);
		mouse_release_settings2(b, x, y, e);
		mlx_put_image_to_window(e->ptr, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	menu(e);
	return (SUCCESS);
}

void	mouse_release_settings2(int b, int x, int y, t_mlx *e)
{
	int		i;

	if ((b == 1) && x >= 47 && x <= 218 && y >= 702 && y <= 735)
	{
		e->data = mlx_xpm_file_to_image(e->ptr, RSUR, &i, &i);
		e->choice = 2;
	}
}

int		mouse_motion_settings(int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 3)
	{
		mlx_destroy_image(e->ptr, e->data);
		if (x >= 303 && x <= 708 && y >= 311 && y <= 365)
			e->data = mlx_xpm_file_to_image(e->ptr, DIFFSUR, &i, &i);
		else if (x >= 331 && x <= 683 && y >= 499 && y <= 554)
			e->data = mlx_xpm_file_to_image(e->ptr, GRASUR, &i, &i);
		else if (x >= 47 && x <= 218 && y >= 702 && y <= 735)
			e->data = mlx_xpm_file_to_image(e->ptr, RSUR, &i, &i);
		else
			e->data = mlx_xpm_file_to_image(e->ptr, SETTINGS, &i, &i);
		mlx_put_image_to_window(e->ptr, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	return (SUCCESS);
}

int		key_hook_settings(int keycode, t_mlx *e)
{
	if (keycode == 53 && e->choice == 3)
	{
		e->choice = 2;
	}
	menu(e);
	return (SUCCESS);
}
