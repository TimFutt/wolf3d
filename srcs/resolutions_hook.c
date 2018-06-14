#include "../includes/wolf3d.h"

int		mouse_clic_resolution(int b, int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 5)
	{
		mlx_destroy_image(e->mlx, e->data);
		if ((b == 1) && x >= 389 && x <= 630 && y >= 208 && y <= 257)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/320CLIC.xpm", &i, &i);
		else if ((b == 1) && x >= 389 && x <= 630 && y >= 300 && y <= 349)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/640CLIC.xpm", &i, &i);
		else if ((b == 1) && x >= 373 && x <= 644 && y >= 394 && y <= 442)
            e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/1280CLIC.xpm", &i, &i);
        else if ((b == 1) && x >= 362 && x <= 665 && y >= 487 && y <= 537)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/1920CLIC.xpm", &i, &i);
		else if ((b == 1) && x >= 362 && x <= 665 && y >= 580 && y <= 630)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/3840CLIC.xpm", &i, &i);
		else if ((b == 1) && x >= 47 && x <= 218 && y >= 702 && y <= 735)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/RETURNCLIC3GRAPHICS.xpm", &i, &i);
		else
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/RESOLUTION.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	return (SUCCESS);
}

int		mouse_release_resolution(int b, int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 5)
	{
		mlx_destroy_image(e->mlx, e->data);
		if ((b == 1) && x >= 389 && x <= 630 && y >= 208 && y <= 257)
		{
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/320SURVOL.xpm", &i, &i);
			e->res = 1;
		}
		else if ((b == 1) && x >= 389 && x <= 630 && y >= 300 && y <= 349)
		{
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/640SURVOL.xpm", &i, &i);
			e->res = 2;
		}
		else if ((b == 1) && x >= 373 && x <= 644 && y >= 394 && y <= 442)
		{
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/1280SURVOL.xpm", &i, &i);
			e->res = 3;
		}
		else if ((b == 1) && x >= 362 && x <= 665 && y >= 487 && y <= 537)
		{
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/1920SURVOL.xpm", &i, &i);
            e->res = 4;
        }
        else if ((b == 1) && x >= 362 && x <= 665 && y >= 415 && y <= 469)
        {
            e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/3840SURVOL.xpm", &i, &i);
            e->res = 5;
        }
        else if ((b == 1) && x >= 47 && x <= 218 && y >= 702 && y <= 735)
        {
            e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/RETURNSURVOL3GRAPHICS.xpm", &i, &i);
            e->choice = 3;
        }
		else
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/RESOLUTION.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
		ft_put_str(e);
	}
	menu(e);
	return (SUCCESS);
}

int		mouse_motion_resolution(int x, int y, t_mlx *e)
{
	int		i;

	if (e->choice == 5)
	{
		mlx_destroy_image(e->mlx, e->data);
		if (x >= 389 && x <= 630 && y >= 208 && y <= 257)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/320SURVOL.xpm", &i, &i);
		else if (x >= 389 && x <= 630 && y >= 300 && y <= 349)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/640SURVOL.xpm", &i, &i);
		else if (x >= 373 && x <= 644 && y >= 394 && y <= 442)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/1280SURVOL.xpm", &i, &i);
		else if (x >= 362 && x <= 665 && y >= 487 && y <= 537)
            e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/1920SURVOL.xpm", &i, &i);
        else if (x >= 362 && x <= 665 && y >= 580 && y <= 630)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/3840SURVOL.xpm", &i, &i);
		else if (x >= 47 && x <= 218 && y >= 702 && y <= 735)
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/RETURNSURVOL3GRAPHICS.xpm", &i, &i);
		else
			e->data = mlx_xpm_file_to_image(e->mlx, "img/xpm/RESOLUTION.xpm", &i, &i);
		mlx_put_image_to_window(e->mlx, e->win, e->data, 0, 0);
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