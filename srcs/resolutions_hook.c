/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolutions_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:10:56 by tifuret           #+#    #+#             */
/*   Updated: 2018/07/11 13:10:57 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		mouse_clic_resolution(int b, int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 5)
	{
		mlx_destroy_image(e->ptr, e->data);
		if ((b == 1) && x >= 389 && x <= 630 && y >= 208 && y <= 257)
			e->data = mlx_xpm_file_to_image(e->ptr, CLIC320, &i, &i);
		else if ((b == 1) && x >= 389 && x <= 630 && y >= 300 && y <= 349)
			e->data = mlx_xpm_file_to_image(e->ptr, CLIC640, &i, &i);
		else if ((b == 1) && x >= 373 && x <= 644 && y >= 394 && y <= 442)
			e->data = mlx_xpm_file_to_image(e->ptr, CLIC1280, &i, &i);
		else if ((b == 1) && x >= 362 && x <= 665 && y >= 487 && y <= 537)
			e->data = mlx_xpm_file_to_image(e->ptr, CLIC1920, &i, &i);
		else if ((b == 1) && x >= 362 && x <= 665 && y >= 580 && y <= 630)
			e->data = mlx_xpm_file_to_image(e->ptr, CLIC3840, &i, &i);
		else if ((b == 1) && x >= 47 && x <= 218 && y >= 702 && y <= 735)
			e->data = mlx_xpm_file_to_image(e->ptr, RCLICGRA, &i, &i);
		else
			e->data = mlx_xpm_file_to_image(e->ptr, RESO, &i, &i);
		mlx_put_image_to_window(e->ptr, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	return (SUCCESS);
}

int		mouse_release_resolution(int b, int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 5)
	{
		mlx_destroy_image(e->ptr, e->data);
		if ((b == 1) && x >= 389 && x <= 630 && y >= 208 && y <= 257)
		{
			e->data = mlx_xpm_file_to_image(e->ptr, SUR320, &i, &i);
			e->res = 1;
		}
		else if ((b == 1) && x >= 389 && x <= 630 && y >= 300 && y <= 349)
		{
			e->data = mlx_xpm_file_to_image(e->ptr, SUR640, &i, &i);
			e->res = 2;
		}
		else
			e->data = mlx_xpm_file_to_image(e->ptr, RESO, &i, &i);
		mouse_release_resolution2(b, x, y, e);
		mlx_put_image_to_window(e->ptr, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	menu(e);
	return (SUCCESS);
}

void	mouse_release_resolution2(int b, int x, int y, t_mlx *e)
{
	int		i;

	if ((b == 1) && x >= 373 && x <= 644 && y >= 394 && y <= 442)
	{
		e->data = mlx_xpm_file_to_image(e->ptr, SUR1280, &i, &i);
		e->res = 3;
	}
	else if ((b == 1) && x >= 362 && x <= 665 && y >= 487 && y <= 537)
	{
		e->data = mlx_xpm_file_to_image(e->ptr, SUR1920, &i, &i);
		e->res = 4;
	}
	else if ((b == 1) && x >= 362 && x <= 665 && y >= 580 && y <= 630)
	{
		e->data = mlx_xpm_file_to_image(e->ptr, SUR3840, &i, &i);
		e->res = 5;
	}
	else if ((b == 1) && x >= 47 && x <= 218 && y >= 702 && y <= 735)
	{
		e->data = mlx_xpm_file_to_image(e->ptr, RSURGRA, &i, &i);
		e->choice = 3;
	}
	else
		e->data = mlx_xpm_file_to_image(e->ptr, RESO, &i, &i);
}

int		mouse_motion_resolution(int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 5)
	{
		mlx_destroy_image(e->ptr, e->data);
		if (x >= 389 && x <= 630 && y >= 208 && y <= 257)
			e->data = mlx_xpm_file_to_image(e->ptr, SUR320, &i, &i);
		else if (x >= 389 && x <= 630 && y >= 300 && y <= 349)
			e->data = mlx_xpm_file_to_image(e->ptr, SUR640, &i, &i);
		else if (x >= 373 && x <= 644 && y >= 394 && y <= 442)
			e->data = mlx_xpm_file_to_image(e->ptr, SUR1280, &i, &i);
		else if (x >= 362 && x <= 665 && y >= 487 && y <= 537)
			e->data = mlx_xpm_file_to_image(e->ptr, SUR1920, &i, &i);
		else if (x >= 362 && x <= 665 && y >= 580 && y <= 630)
			e->data = mlx_xpm_file_to_image(e->ptr, SUR3840, &i, &i);
		else if (x >= 47 && x <= 218 && y >= 702 && y <= 735)
			e->data = mlx_xpm_file_to_image(e->ptr, RSURGRA, &i, &i);
		else
			e->data = mlx_xpm_file_to_image(e->ptr, RESO, &i, &i);
		mlx_put_image_to_window(e->ptr, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	return (SUCCESS);
}

int		key_hook_resolution(int keycode, t_mlx *e)
{
	if (keycode == 53 && e->choice == 5)
	{
		e->choice = 3;
	}
	menu(e);
	return (SUCCESS);
}
