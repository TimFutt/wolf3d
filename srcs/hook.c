/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:54:47 by tifuret           #+#    #+#             */
/*   Updated: 2018/07/16 15:54:48 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int    ft_keys_moove(int keycode, t_mlx *e)
{
    if (keycode == 123)
    {
        e->angle += 0.1;
        //e->a.x += 0.2;
        //e->a.y += 0.2;
        printf("%f\n", e->angle);
    }
    raycasting(/*player,*/ grid, PI * 0.8, mlx);
    mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
    return (0);
}

int		ft_events(int keycode, t_mlx *e)
{
    ft_keys_moove(keycode, e);
    printf("%i\n", keycode);
    if (keycode == 53)
        exit(0);
	return (0);
}

void	ft_keys(t_mlx *e)
{
    mlx_key_hook(e->win, ft_events, e);
    //mlx_hook(e->win, 6, 0, ft_events, e);
}