#include "../includes/wolf3d.h"

int		mouse_clic_difficulty(int b, int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 4)
	{
		mlx_destroy_image(e->mlx, e->data);
		if ((b == 1) && x >= 424 && x <= 601 && y >= 290 && y <= 344)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/EASYCLIC.xpm", &i, &i);
		else if ((b == 1) && x >= 360 && x <= 651 && y >= 415 && y <= 469)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/CLASSICCLIC.xpm", &i, &i);
		else if ((b == 1) && x >= 317 && x <= 695 && y >= 541 && y <= 595)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/HARDCORECLIC.xpm", &i, &i);
		else if ((b == 1) && x >= 47 && x <= 218 && y >= 702 && y <= 735)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/RETURNCLIC2DIFFICULTY.xpm", &i, &i);
		else
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/MENUDIFFICULTY.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	return (SUCCESS);
}

int		mouse_release_difficulty(int b, int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 4)
	{
		mlx_destroy_image(e->mlx, e->data);
		if ((b == 1) && x >= 424 && x <= 601 && y >= 290 && y <= 344)
		{
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/EASYCLIC.xpm", &i, &i);
			e->diff = 1;
		}
		else if ((b == 1) && x >= 360 && x <= 651 && y >= 415 && y <= 469)
		{
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/CLASSICSURVOL.xpm", &i, &i);
			e->diff = 2;
		}
		else if ((b == 1) && x >= 317 && x <= 695 && y >= 541 && y <= 595)
		{
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/HARDCORESURVOL.xpm", &i, &i);
			e->diff = 3;
		}
		else if ((b == 1) && x >= 47 && x <= 218 && y >= 702 && y <= 735)
		{
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/RETURNSURVOL2DIFFUCULTY.xpm", &i, &i);
			e->choice = 3;
		}
		else
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/MENUDIFFICULTY.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	menu(e);
	return (SUCCESS);
}

int		mouse_motion_difficulty(int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 4)
	{
		mlx_destroy_image(e->mlx, e->data);
		if (x >= 424 && x <= 601 && y >= 290 && y <= 344)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/EASYSURVOL.xpm", &i, &i);
		else if (x >= 360 && x <= 651 && y >= 415 && y <= 469)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/CLASSICSURVOL.xpm", &i, &i);
		else if (x >= 317 && x <= 695 && y >= 541 && y <= 595)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/HARDCORESURVOL.xpm", &i, &i);
		else if (x >= 47 && x <= 218 && y >= 702 && y <= 735)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/RETURNSURVOL2DIFFUCULTY.xpm", &i, &i);
		else
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/MENUDIFFICULTY.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
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