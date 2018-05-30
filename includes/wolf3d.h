#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include <mlx.h>
# include <sys/types.h>
# include <sys/uio.h>
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define ESC 53

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
	int				choice;
}					t_menu;

void				init(t_menu *men);
void				destroy_window(t_menu *men);
void				menu(t_menu *men, int choice);
int					key_hook_menu(int key, void *param);
int					mouse_motion_hook(int x, int y, void *param);
int					mouse_motion_hook_menu(int x, int y, void *param);
int					mouse_hook_menu(int button, int x, int y, void *param);
int					mouse_release_hook_menu(int b, int x, int y, void *param);

#endif
