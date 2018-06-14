#include "../includes/wolf3d.h"

void	init(t_mlx *e)
{
	void	*mlx;

	e->mlx = mlx_init();
	mlx = e->mlx;
	e->win = NULL;
	e->choice = 1;
	e->diff = 2;
	e->res = 3;
}

int		main()
{
	t_mlx	e;

	init(&e);
	menu(&e);
	mlx_loop(e.mlx);
	return (0);
}
