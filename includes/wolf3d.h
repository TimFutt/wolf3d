/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:19:39 by chaydont          #+#    #+#             */
/*   Updated: 2018/11/01 16:07:05 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

# define SUCCESS 1
# define ERROR 0

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define EXIT 53

# define START "img/xpm/START.xpm"
# define MENU "img/xpm/MENU.xpm"
# define SETTINGS "img/xpm/SETTINGS.xpm"
# define DIFF "img/xpm/DIFF.xpm"
# define RESO "img/xpm/RESO.xpm"

# define EZCLIC "img/xpm/EASYCLIC.xpm"
# define CLACLIC "img/xpm/CLASSICCLIC.xpm"
# define HARDCLIC "img/xpm/HARDCORECLIC.xpm"
# define RCLICDIFF "img/xpm/RETURNCLIC2DIFFICULTY.xpm"

# define EZSUR "img/xpm/EASYSURVOL.xpm"
# define CLASUR "img/xpm/CLASSICSURVOL.xpm"
# define HARDSUR "img/xpm/HARDCORESURVOL.xpm"
# define RSURDIFF "img/xpm/RETURNSURVOL2DIFFUCULTY.xpm"

# define MENUC1 "img/xpm/MENUCLIC1.xpm"
# define MENUC2 "img/xpm/MENUCLIC2.xpm"
# define MENUC3 "img/xpm/MENUCLIC3.xpm"

# define MENUSUR1 "img/xpm/MENUSURVOL1.xpm"
# define MENUSUR2 "img/xpm/MENUSURVOL2.xpm"
# define MENUSUR3 "img/xpm/MENUSURVOL3.xpm"

# define CLIC320 "img/xpm/320CLIC.xpm"
# define CLIC640 "img/xpm/640CLIC.xpm"
# define CLIC1280 "img/xpm/1280CLIC.xpm"
# define CLIC1920 "img/xpm/1920CLIC.xpm"
# define CLIC3840 "img/xpm/3840CLIC.xpm"
# define RCLICGRA "img/xpm/RETURNCLIC3GRAPHICS.xpm"

# define SUR320 "img/xpm/320SURVOL.xpm"
# define SUR640 "img/xpm/640SURVOL.xpm"
# define SUR1280 "img/xpm/1280SURVOL.xpm"
# define SUR1920 "img/xpm/1920SURVOL.xpm"
# define SUR3840 "img/xpm/3840SURVOL.xpm"
# define RSURGRA "img/xpm/RETURNSURVOL3GRAPHICS.xpm"

# define DIFFCLIC "img/xpm/DIFFICULTYCLIC.xpm"
# define GRACLIC "img/xpm/GRAPHICSCLIC.xpm"
# define RCLIC "img/xpm/RETURNCLIC1.xpm"

# define DIFFSUR "img/xpm/DIFFICULTYSURVOL.xpm"
# define GRASUR "img/xpm/GRAPHICSSURVOL.xpm"
# define RSUR "img/xpm/RETURNSURVOL1.xpm"

# define NORTH "textures/greystone.xpm"
# define SOUTH "textures/redbrick.xpm"
# define EST "textures/wood.xpm"
# define WEST "textures/hitler.xpm"

# define WINDOW_HEIGHT 1200
# define WINDOW_WIDTH 1500
# define PI 3.141592653589789

typedef struct		s_pov
{
	double	angle;
	double	x;
	double	y;
	int		i;
	double	fov;
	int		head;
	double	zoom;
}					t_pov;

typedef struct		s_tex
{
	int			x;
	int			y;
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}					t_tex;

typedef struct		s_mlx
{
	char	*str;
	void	*img;
	void	*data;
	void	*ptr;
	void	*win;
	int		choice;
	int		diff;
	int		res;
	int		bpp;
	int		s_l;
	int		endian;
	int		**map;
	int		length;
	int		height;
	int		ox;
	int		oy;
	int		side;
	double	rtspd;
	double	xdir;
	double	ydir;
	t_pov	p;
	t_tex	tex[4];
	int		cc;
}					t_mlx;

void				menu(t_mlx *e);
void				menu2(t_mlx *e);
void				menu3(t_mlx *e);
void				menu4(t_mlx *e);
int					key_hook_menu(int keycode, t_mlx *e);
int					mouse_motion_menu(int x, int y, t_mlx *e);
int					mouse_clic_menu(int b, int x, int y, t_mlx *e);
int					mouse_release_menu(int b, int x, int y, t_mlx *e);
void				mouse_release_menu2(int b, int x, int y, t_mlx *e);

int					key_hook_settings(int keycode, t_mlx *e);
int					mouse_motion_settings(int x, int y, t_mlx *e);
int					mouse_clic_settings(int b, int x, int y, t_mlx *e);
int					mouse_release_settings(int b, int x, int y, t_mlx *e);
void				mouse_release_settings2(int b, int x, int y, t_mlx *e);

int					key_hook_difficulty(int keycode, t_mlx *e);
int					mouse_motion_difficulty(int x, int y, t_mlx *e);
int					mouse_clic_difficulty(int b, int x, int y, t_mlx *e);
int					mouse_release_difficulty(int b, int x, int y, t_mlx *e);
void				mouse_release_difficulty2(int b, int x, int y, t_mlx *e);

int					key_hook_resolution(int keycode, t_mlx *e);
int					mouse_motion_resolution(int x, int y, t_mlx *e);
int					mouse_clic_resolution(int b, int x, int y, t_mlx *e);
int					mouse_release_resolution(int b, int x, int y, t_mlx *e);
void				mouse_release_resolution2(int b, int x, int y, t_mlx *e);

void				ft_put_str(t_mlx *e);
void				ft_keys(t_mlx *e);
int					ft_events(int keycode, t_mlx *mlx);
int					ft_keys_moove(int keycode, t_mlx *mlx);
int					ft_keys_moove2(int keycode, t_mlx *mlx);
int					ft_mouse_pos(int x, int y, t_mlx *mlx);
int					mouse_button(int button, int x, int y, t_mlx *mlx);
int					hook_close(t_mlx *mlx);

int					open_file(t_mlx *e, char *file);
void				error_map();
void				usage();

void				raycasting(t_pov player, int **grid, t_mlx mlx);

void				drawcolumn(double dist, double l, int x, t_mlx mlx);

void				load_textures(t_mlx *t);
#endif
