/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:19:39 by chaydont          #+#    #+#             */
/*   Updated: 2018/06/09 15:23:05 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include <mlx.h>

typedef struct		s_mlx
{
	char	*img;
	void	*data;
	void	*mlx;
	void	*win;
}					t_mlx;

typedef struct		s_img
{
	char		*NORTH;
	char		*SOUTH;
	char		*EST;
	char		*WEST;
}					t_img;

void				menu(t_mlx *men);
int					key_hook_menu(int key, void *param);
int					mouse_motion_hook(int x, int y, void *param);
int					mouse_motion_hook_menu(int x, int y, void *param);
int					mouse_hook_menu(int button, int x, int y, void *param);
int					mouse_release_hook_menu(int b, int x, int y, void *param);

#endif
