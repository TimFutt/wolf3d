/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:25:31 by tifuret           #+#    #+#             */
/*   Updated: 2018/11/01 15:33:49 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	load_textures(t_mlx *t)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	t->tex[0].img = mlx_xpm_file_to_image(t->str, NORTH, &a, &b);
	t->tex[0].data = mlx_get_data_addr(t->tex[0].img,
	&t->tex[0].bpp, &t->tex[0].sizeline, &t->tex[0].endian);
	t->tex[1].img = mlx_xpm_file_to_image(t->str, SOUTH, &a, &b);
	t->tex[1].data = mlx_get_data_addr(t->tex[1].img,
	&t->tex[1].bpp, &t->tex[1].sizeline, &t->tex[1].endian);
	t->tex[2].img = mlx_xpm_file_to_image(t->str, EST, &a, &b);
	t->tex[2].data = mlx_get_data_addr(t->tex[2].img,
	&t->tex[2].bpp, &t->tex[2].sizeline, &t->tex[2].endian);
	t->tex[3].img = mlx_xpm_file_to_image(t->str, WEST, &a, &b);
	t->tex[3].data = mlx_get_data_addr(t->tex[3].img,
	&t->tex[3].bpp, &t->tex[3].sizeline, &t->tex[3].endian);
}
