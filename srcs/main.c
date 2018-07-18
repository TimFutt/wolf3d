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
/*
int		init_player(t_mlx *mlx, int j, int i)
{
	while (mlx->map[j])
	{
		i = 0;
		while (mlx->map[j][i])
		{
			if (mlx->map[j][i] == 'X')
			{
				//mlx->xpos = j;
				//mlx->ypos = i;
				//mlx->xdir = -1;
				//mlx->ydir = 0;
				//mlx->mvspd = 0.2;
				//mlx->rtspd = 0.05;
				//mlx->sprint = 0;
				return (0);
			}
			i++;
		}
		j++;
	}
	ft_putendl("error : player not found in map");
	return (-1);

*/

int			borders(char *buf, int i)
{
	while (buf[i] != '\n')
	{
		if (buf[i] != '1')
			return (-1);
		i++;
	}
	while (buf[i])
	{
		i++;
		if (buf[i] != '1')
			return (-1);
		while (buf[i] != '\0' && buf[i] != '\n')
			i++;
		if (buf[i - 1] != '1')
			return (-1);
	}
	i--;
	while (buf[i] != '\n')
	{
		if (buf[i] != '1')
			return (-1);
		i--;
	}
	return (0);
}

char	*joiner(char *s1, char *s2)
{
	char	*n;
	int		i[2];

	i[0] = 0;
	while (s1[i[0]])
		i[0]++;
	i[1] = 0;
	while (s2[i[1]])
		i[1]++;
	n = (char *)malloc(sizeof(char) * (i[0] + i[1] + 1));
	i[0] = 0;
	while (s1[i[0]])
	{
		n[i[0]] = s1[i[0]];
		i[0]++;
	}
	free(s1);
	i[1] = 0;
	while (s2[i[1]])
	{
		n[i[0] + i[1]] = s2[i[1]];
		i[1]++;
	}
	n[i[0] + i[1]] = '\0';
	return (n);
}

int		len_line(char *buf, int k)
{
	int	len;

	len = 0;
	while (buf[k] != '\n' && buf[k] != '\0')
	{
		k++;
		len++;
	}
	return (len);
}

int		check_char(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
		i++;
	buf[i - 1] = '\0';
	i = 0;
	while (buf[i])
	{
		if (buf[i] != '\n' && buf[i] != '0' && buf[i] != '1'\
				&& buf[i] != 'X' && buf[i] != '\0')
		{
			ft_putendl("error: invalid characters in map");
			return (-1);
		}
		i++;
	}
	if (borders(buf, 0) == -1)
	{
		ft_putendl("error: map must have borders");
		return (-1);
	}
	return (0);
}

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

static int		start(char *s, int *fd)
{
	if (BUFF_SIZE < 1)
	{
		ft_putstr_fd("error: BUFF_SIZE must be greater than 0\n", 2);
		return (-1);
	}
	if ((*fd = open(s, O_RDONLY)) == -1)
	{
		ft_putendl(ft_strjoin("error: ", strerror(errno)));
		return (-1);
	}
	return (1);
}

static char		*buffer(char *s, int *nbl)
{
	int		fd;
	char	*buf;
	char	*line;

	buf = ft_strnew(0);
	if (start(s, &fd) == -1)
		return (NULL);
	while (get_next_line(fd, &line) > 0 && (*nbl)++ > -1)
	{
		buf = joiner(joiner(buf, line), "\n");
		ft_strdel(&line);
	}
	if (check_char(buf) == -1)
		return (NULL);
	if (close(fd) == -1)
	{
		ft_putendl(ft_strjoin("error: ", strerror(errno)));
		return (NULL);
	}
	return (buf);
}

static char		**fillmap(char *buf, int nbl, int j, t_mlx *mlx)
{
	int		i;
	int		k;
	char	**map;

	k = 0;
	if (!buf)
		return (NULL);
	if (!(map = (char **)malloc(sizeof(char *) * nbl)))
		return (NULL);
	while (buf[k] != '\0' && j < nbl)
	{
		i = 0;
		if (!(map[j] = (char *)malloc(sizeof(char) * len_line(buf, k))))
			return (NULL);
		while (buf[k] != '\n' && buf[k] != '\0')
			map[j][i++] = buf[k++];
		map[j][i] = '\0';
		k++;
		j++;
		mlx->len = i;
	}
	return (map);
}

/*
void	init_map(t_mlx *e)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return ;
	e->ptr = mlx_init();
	e->win = NULL;
	e->choice = 1;
	e->diff = 2;
	e->res = 3;
}
*/

static t_mlx	*init_map(char *s)
{
	t_mlx	*mlx;
	char	*buf;
	char	*name;

	name = ft_strjoin("wolf3d :", s);
	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
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
	mlx->d = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->s_l,
			&mlx->endian);
	buf = buffer(s, &(mlx->nbl));
	if ((mlx->map = fillmap(buf, mlx->nbl, 0, mlx)) == NULL)
		return (NULL);
	free(buf);
	//if (init_player(mlx, 0, 0) == -1)
	//	return (NULL);
	//mlx->xplane = 0.0;
	//mlx->yplane = 0.6;
	//mlx->dh = 2.0;
	return (mlx);
}

/*
int				main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac == 2 && av[1])
	{
		if ((mlx = init_mlx(av[1])) == NULL)
			return (0);
		drawer(mlx);
		mlx_hook(mlx->win, 2, (1L << 0), key_press, mlx);
		mlx_loop(mlx->mlx);
		mlx_destroy_window(mlx->mlx, mlx->win);
	}
	return (0);
}
*/

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
			init_map("test");
	}
	else
	{
		ft_putendl("Error : wrong entry.");
		ft_putendl("usage: ./wolf3d [-menu, (path)]");
	}
	return (0);
}