/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:10:33 by tifuret           #+#    #+#             */
/*   Updated: 2018/10/24 16:27:04 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			error_map(void)
{
	ft_putendl("Error map");
	exit(1);
}

static void		init_menu(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = NULL;
	mlx->p.angle = 2.5 * PI;
	mlx->p.i = -1;
	mlx->p.fov = PI * 0.3;
	mlx->choice = 1;
	mlx->diff = 2;
	mlx->res = 3;
}

static void		init_map(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Wolf 3D");
	mlx->img = mlx_new_image(mlx->ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx->str = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->s_l, &mlx->endian);
	ft_keys(mlx);
	mlx->p.angle = 2.5 * PI;
	mlx->p.i = -1;
	mlx->p.fov = PI * 0.3;
	mlx->choice = 1;
	mlx->diff = 2;
	mlx->res = 3;
	load_textures(mlx);
}

void			menu_main(char *file, t_mlx *mlx)
{
	if (!(open_file(mlx, file)))
	{
		error_map();
		return ;
	}
	init_menu(mlx);
	menu(mlx);
	mlx_loop(mlx->ptr);
}

int				main(int ac, char **av)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (0);
	if (ac == 3)
	{
		if (!ft_strcmp(av[1], "-menu"))
			menu_main(av[2], mlx);
	}
	else if (ac == 2)
	{
		if (!(open_file(mlx, av[1])))
		{
			error_map();
			return (0);
		}
		init_map(mlx);
		raycasting(mlx->p, mlx->map, *mlx);
		mlx_loop(mlx->ptr);
	}
	else
		usage();
	return (0);
}
