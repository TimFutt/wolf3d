# include "../includes/wolf3d.h"

void	init_menu_settings(t_menu *men)
{
	void	*mlx;

	men->mlx = mlx_init();
	mlx = men->mlx;
	men->win = NULL;
	men->win = NULL;
	men->choice = 1;
}

void	init(t_menu *men)
{
	init_menu_settings(men);
}
