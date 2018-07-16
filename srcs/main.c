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

int		main(void)
{
	t_mlx	e;

	init(&e);
	menu(&e);
	mlx_loop(e.mlx);
	return (0);
}
