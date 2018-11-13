/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:10:45 by tifuret           #+#    #+#             */
/*   Updated: 2018/07/11 13:10:46 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		mouse_clic_menu(int b, int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 2)
	{
		mlx_destroy_image(e->ptr, e->data);
		if ((b == 1) && x >= 128 && x <= 888 && y >= 290 && y <= 387)
			e->data = mlx_xpm_file_to_image(e->ptr, MENUC1, &i, &i);
		else if ((b == 1) && x >= 128 && x <= 473 && y >= 445 && y <= 500)
			e->data = mlx_xpm_file_to_image(e->ptr, MENUC2, &i, &i);
		else if ((b == 1) && x >= 128 && x <= 290 && y >= 560 && y <= 617)
			e->data = mlx_xpm_file_to_image(e->ptr, MENUC3, &i, &i);
		else
			e->data = mlx_xpm_file_to_image(e->ptr, MENU, &i, &i);
		mlx_put_image_to_window(e->ptr, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	return (SUCCESS);
}

int		mouse_release_menu(int b, int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 2)
	{
		mlx_destroy_image(e->ptr, e->data);
		if ((b == 1) && x >= 128 && x <= 888 && y >= 290 && y <= 387)
		{
			e->data = mlx_xpm_file_to_image(e->ptr, MENUSUR1, &i, &i);
			e->choice = 6;
		}
		else if ((b == 1) && x >= 128 && x <= 473 && y >= 445 && y <= 500)
		{
			e->data = mlx_xpm_file_to_image(e->ptr, MENUSUR2, &i, &i);
			e->choice = 3;
		}
		else
			e->data = mlx_xpm_file_to_image(e->ptr, MENU, &i, &i);
		mouse_release_menu2(b, x, y, e);
		mlx_put_image_to_window(e->ptr, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	menu(e);
	return (SUCCESS);
}

void	mouse_release_menu2(int b, int x, int y, t_mlx *e)
{
	int		i;

	if ((b == 1) && x >= 128 && x <= 290 && y >= 560 && y <= 617)
	{
		e->data = mlx_xpm_file_to_image(e->ptr, MENUSUR3, &i, &i);
		exit(0);
	}
}

int		mouse_motion_menu(int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 2)
	{
		mlx_destroy_image(e->ptr, e->data);
		if (x >= 128 && x <= 888 && y >= 290 && y <= 387)
			e->data = mlx_xpm_file_to_image(e->ptr, MENUSUR1, &i, &i);
		else if (x >= 128 && x <= 473 && y >= 445 && y <= 500)
			e->data = mlx_xpm_file_to_image(e->ptr, MENUSUR2, &i, &i);
		else if (x >= 128 && x <= 290 && y >= 560 && y <= 617)
			e->data = mlx_xpm_file_to_image(e->ptr, MENUSUR3, &i, &i);
		else
			e->data = mlx_xpm_file_to_image(e->ptr, MENU, &i, &i);
		mlx_put_image_to_window(e->ptr, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	return (SUCCESS);
}

int		key_hook_menu(int keycode, t_mlx *e)
{
	if (keycode == EXIT)
		exit(0);
	if (keycode == 36 && e->choice == 1)
	{
		e->choice = 2;
	}
	menu(e);
	return (SUCCESS);
}
