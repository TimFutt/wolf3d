#include "../includes/wolf3d.h"

int		mouse_clic_menu(int b, int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 2)
	{
		mlx_destroy_image(e->mlx, e->data);
		if ((b == 1) && x >= 128 && x <= 888 && y >= 290 && y <= 387)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/MENUCLIC1.xpm", &i, &i);
		else if ((b == 1) && x >= 128 && x <= 473 && y >= 445 && y <= 500)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/MENUCLIC2.xpm", &i, &i);
		else if ((b == 1) && x >= 128 && x <= 290 && y >= 560 && y <= 617)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/MENUCLIC3.xpm", &i, &i);
		else
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/WOLF3DMENU.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	return (SUCCESS);
}

int		mouse_release_menu(int b, int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 2)
	{
		mlx_destroy_image(e->mlx, e->data);
		if ((b == 1) && x >= 128 && x <= 888 && y >= 290 && y <= 387)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/MENUSURVOL1.xpm", &i, &i);
		else if ((b == 1) && x >= 128 && x <= 473 && y >= 445 && y <= 500)
		{
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/MENUSURVOL2.xpm", &i, &i);
			e->choice = 3;
		}
		else if ((b == 1) && x >= 128 && x <= 290 && y >= 560 && y <= 617)
		{
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/MENUSURVOL3.xpm", &i, &i);
			exit(0);
		}
		else
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/WOLF3DMENU.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	menu(e);
	return (SUCCESS);
}

int		mouse_motion_menu(int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 2)
	{
		mlx_destroy_image(e->mlx, e->data);
		if (x >= 128 && x <= 888 && y >= 290 && y <= 387)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/MENUSURVOL1.xpm", &i, &i);
		else if (x >= 128 && x <= 473 && y >= 445 && y <= 500)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/MENUSURVOL2.xpm", &i, &i);
		else if (x >= 128 && x <= 290 && y >= 560 && y <= 617)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/MENUSURVOL3.xpm", &i, &i);												
		else
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/WOLF3DMENU.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	return (SUCCESS);
}

int		key_hook_menu(int keycode, t_mlx *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 36 && e->choice == 1)
	{
		e->choice = 2;
	}
	menu(e);
	return (SUCCESS);
}
