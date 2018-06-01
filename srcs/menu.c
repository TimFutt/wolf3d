#include "../includes/fractol.h"

void	menu(t_menu *men)
{
	int		i;

	if (men->win)
	{
		mlx_destroy_window(men->mlx, men->win);
		men->win = NULL;
	}
	/*if (choice == 1)
		exit(0);
	else if (choice == 2)
		exit(0);
	else if (choice == 3)
		exit(0);
	else if (choice == 4)*/
	//{
		men->win = mlx_new_window(men->mlx, 1024, 768, "Menu");
		men->data = mlx_xpm_file_to_image(men->mlx, "img/xpm/menu.xpm", &i, &i);
		mlx_put_image_to_window(men->mlx, men->win, men->data, 0, 0);
		mlx_key_hook(men->win, key_hook_menu, men);
		mlx_hook(men->win, 4, (1L << 2), mouse_hook_menu, men);
		mlx_hook(men->win, 5, (1L << 2), mouse_release_hook_menu, men);
		mlx_hook(men->win, 6, (1L << 2), mouse_motion_hook_menu, men);
	//}
	/*else if (choice == 5)
		exit(0);
	else
		exit(0);*/
}
