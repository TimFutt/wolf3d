#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include <mlx.h>

typedef struct		s_pal
{
	struct s_pal	*before;
	struct s_pal	*nx;
}					t_pal;

typedef struct		s_menu
{
	char			*img;
	void			*data;
	void			*mlx;
	void			*win;
}					t_menu;

void				menu(t_menu *men);
int					key_hook_menu(int key, void *param);
int					mouse_motion_hook(int x, int y, void *param);
int					mouse_motion_hook_menu(int x, int y, void *param);
int					mouse_hook_menu(int button, int x, int y, void *param);
int					mouse_release_hook_menu(int b, int x, int y, void *param);

#endif
