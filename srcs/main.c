/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:10:33 by tifuret           #+#    #+#             */
/*   Updated: 2018/07/11 13:10:35 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_menu(t_mlx *e)
{
	void	*mlx;

	e->ptr = mlx_init();
	mlx = e->ptr;
	e->win = NULL;
	e->choice = 1;
	e->diff = 2;
	e->res = 3;
}

t_mlx	*init_map(char *s)
{
	t_mlx	*mlx;
	char	*buf;
	char	*name;

	name = ft_strjoin("wolf3d :", s);
	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	buf = buffer(s, &(mlx->nbl));
	if ((mlx->map = fillmap(buf, mlx->nbl, mlx)) == NULL)
		return (NULL);
	mlx->win = NULL;
	mlx->choice = 1;
	mlx->diff = 2;
	mlx->res = 3;
	mlx->nbl = 0;
	mlx->ptr = mlx_init();
	mlx->img = mlx_new_image(mlx->ptr, WIN_X, WIN_Y);
	mlx->win = mlx_new_window(mlx->ptr, WIN_X, WIN_Y, name);
	free(name);
	mlx->d = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->s_l, &mlx->endian);
	buf = buffer(s, &(mlx->nbl));
	free(buf);
	return (mlx);
}

int		main(int ac, char **av)
{
	t_mlx	e;

	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "-menu"))
		{
			init_menu(&e);
			menu(&e);
			mlx_loop(e.ptr);
		}
		else
			init_map(av[1]);
	}
	else
	{
		ft_putendl("Error : wrong entry.");
		ft_putendl("usage: ./wolf3d [-menu, (path)]");
	}
	return (0);
}