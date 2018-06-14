/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:19:39 by chaydont          #+#    #+#             */
/*   Updated: 2018/06/14 16:35:38 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include <mlx.h>

#define SUCCESS 1

/*
 * ** Choice 1 = Ecran accueil
 * ** Choice 2 = Menu
 * ** Choice 3 = Settings
 * ** Choice 4 = Difficulty
 * ** Choice 5 = Resolution
 * */

/*
 * ** Diff 1 = Easy
 * ** Diff 2 = Classic
 * ** Diff 3 = Hardcore
 * */

typedef struct		s_mlx
{
	char	*img;
	void	*data;
	void	*mlx;
	void	*win;
	int		choice;
	int		diff;
	int		res;
}					t_mlx;

typedef struct		s_img
{
	char		*NORTH;
	char		*SOUTH;
	char		*EST;
	char		*WEST;
}					t_img;


void				menu(t_mlx *e);
int					key_hook_menu(int keycode, t_mlx *e);
int					mouse_motion_menu(int x, int y, t_mlx *e);
int					mouse_clic_menu(int b, int x, int y, t_mlx *e);
int					mouse_release_menu(int b, int x, int y, t_mlx *e);


int					key_hook_settings(int keycode, t_mlx *e);
int					mouse_motion_settings(int x, int y, t_mlx *e);
int					mouse_clic_settings(int b, int x, int y, t_mlx *e);
int					mouse_release_settings(int b, int x, int y, t_mlx *e);


int					key_hook_difficulty(int keycode, t_mlx *e);
int					mouse_motion_difficulty(int x, int y, t_mlx *e);
int					mouse_clic_difficulty(int b, int x, int y, t_mlx *e);
int					mouse_release_difficulty(int b, int x, int y, t_mlx *e);

int					key_hook_resolution(int keycode, t_mlx *e);
int					mouse_motion_resolution(int x, int y, t_mlx *e);
int					mouse_clic_resolution(int b, int x, int y, t_mlx *e);
int					mouse_release_resolution(int b, int x, int y, t_mlx *e);

void				ft_put_str(t_mlx *e);

#endif
