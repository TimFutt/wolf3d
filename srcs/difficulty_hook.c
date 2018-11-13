/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difficulty_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 16:38:52 by tifuret           #+#    #+#             */
/*   Updated: 2018/07/18 16:38:53 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		mouse_clic_difficulty(int b, int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 4)
	{
		mlx_destroy_image(e->ptr, e->data);
		if ((b == 1) && x >= 424 && x <= 601 && y >= 290 && y <= 344)
			e->data = mlx_xpm_file_to_image(e->ptr, EZCLIC, &i, &i);
		else if ((b == 1) && x >= 360 && x <= 651 && y >= 415 && y <= 469)
			e->data = mlx_xpm_file_to_image(e->ptr, CLACLIC, &i, &i);
		else if ((b == 1) && x >= 317 && x <= 695 && y >= 541 && y <= 595)
			e->data = mlx_xpm_file_to_image(e->ptr, HARDCLIC, &i, &i);
		else if ((b == 1) && x >= 47 && x <= 218 && y >= 702 && y <= 735)
			e->data = mlx_xpm_file_to_image(e->ptr, RCLICDIFF, &i, &i);
		else
			e->data = mlx_xpm_file_to_image(e->ptr, DIFF, &i, &i);
		mlx_put_image_to_window(e->ptr, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	return (SUCCESS);
}

int		mouse_release_difficulty(int b, int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 4)
	{
		mlx_destroy_image(e->ptr, e->data);
		if ((b == 1) && x >= 424 && x <= 601 && y >= 290 && y <= 344)
		{
			e->data = mlx_xpm_file_to_image(e->ptr, EZCLIC, &i, &i);
			e->diff = 1;
		}
		else if ((b == 1) && x >= 360 && x <= 651 && y >= 415 && y <= 469)
		{
			e->data = mlx_xpm_file_to_image(e->ptr, CLACLIC, &i, &i);
			e->diff = 2;
		}
		else
			e->data = mlx_xpm_file_to_image(e->ptr, DIFF, &i, &i);
		mouse_release_difficulty2(b, x, y, e);
		mlx_put_image_to_window(e->ptr, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	menu(e);
	return (SUCCESS);
}

void	mouse_release_difficulty2(int b, int x, int y, t_mlx *e)
{
	int		i;

	if ((b == 1) && x >= 317 && x <= 695 && y >= 541 && y <= 595)
	{
		e->data = mlx_xpm_file_to_image(e->ptr, HARDCLIC, &i, &i);
		e->diff = 3;
	}
	else if ((b == 1) && x >= 47 && x <= 218 && y >= 702 && y <= 735)
	{
		e->data = mlx_xpm_file_to_image(e->ptr, RCLICDIFF, &i, &i);
		e->choice = 3;
	}
}

int		mouse_motion_difficulty(int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 4)
	{
		mlx_destroy_image(e->ptr, e->data);
		if (x >= 424 && x <= 601 && y >= 290 && y <= 344)
			e->data = mlx_xpm_file_to_image(e->ptr, EZSUR, &i, &i);
		else if (x >= 360 && x <= 651 && y >= 415 && y <= 469)
			e->data = mlx_xpm_file_to_image(e->ptr, CLASUR, &i, &i);
		else if (x >= 317 && x <= 695 && y >= 541 && y <= 595)
			e->data = mlx_xpm_file_to_image(e->ptr, HARDSUR, &i, &i);
		else if (x >= 47 && x <= 218 && y >= 702 && y <= 735)
			e->data = mlx_xpm_file_to_image(e->ptr, RSURDIFF, &i, &i);
		else
			e->data = mlx_xpm_file_to_image(e->ptr, DIFF, &i, &i);
		mlx_put_image_to_window(e->ptr, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	return (SUCCESS);
}

int		key_hook_difficulty(int keycode, t_mlx *e)
{
	if (keycode == 53 && e->choice == 4)
	{
		e->choice = 3;
	}
	menu(e);
	return (SUCCESS);
}
