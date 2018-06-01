#include "../includes/fractol.h"

void	init(t_menu *men)
{
	void	*mlx;

	men->mlx = mlx_init();
	mlx = men->mlx;
	men->win = NULL;
}

int		main()
{
	t_menu	men;

	init(&men);
	menu(&men);
	mlx_loop(men.mlx);
	return (0);
}
