#include "../includes/wolf3d.h"

int		mouse_clic_settings(int b, int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 3)
	{
		mlx_destroy_image(e->mlx, e->data);
		if ((b == 1) && x >= 303 && x <= 708 && y >= 311 && y <= 365)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/DIFFICULTYCLIC.xpm", &i, &i);
		else if ((b == 1) && x >= 331 && x <= 683 && y >= 499 && y <= 554)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/GRAPHICSCLIC.xpm", &i, &i);
		else if ((b == 1) && x >= 47 && x <= 218 && y >= 702 && y <= 735)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/RETURNCLIC1.xpm", &i, &i);
		else
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/SETTINGS.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	return (SUCCESS);
}

int		mouse_release_settings(int b, int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 3)
	{
		mlx_destroy_image(e->mlx, e->data);
		if ((b == 1) && x >= 128 && x <= 888 && y >= 290 && y <= 387)
		{
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/DIFFICULTYSURVOL.xpm", &i, &i);
			e->choice = 4;
		}
		else if ((b == 1) && x >= 331 && x <= 683 && y >= 499 && y <= 554)
		{
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/GRAPHICSSURVOL.xpm", &i, &i);
			e->choice = 5;
		}
		else if ((b == 1) && x >= 47 && x <= 218 && y >= 702 && y <= 735)
		{
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/RETURNSURVOL1.xpm", &i, &i);
			e->choice = 2;
		}
		else
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/SETTINGS.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	menu(e);
	return (SUCCESS);
}

int		mouse_motion_settings(int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 3)
	{
		mlx_destroy_image(e->mlx, e->data);
		if (x >= 303 && x <= 708 && y >= 311 && y <= 365)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/DIFFICULTYSURVOL.xpm", &i, &i);
		else if (x >= 331 && x <= 683 && y >= 499 && y <= 554)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/GRAPHICSSURVOL.xpm", &i, &i);
		else if (x >= 47 && x <= 218 && y >= 702 && y <= 735)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/RETURNSURVOL1.xpm", &i, &i);
		else
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/SETTINGS.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
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