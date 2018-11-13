/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:11:06 by tifuret           #+#    #+#             */
/*   Updated: 2018/10/16 13:39:27 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		read_pos(int fd, t_mlx *e)
{
	char	*line;
	int		i;
	char	**line_split;

	i = -1;
	if (get_next_line(fd, &line) < 1)
		error_map();
	line_split = ft_strsplit(line, ' ');
	ft_strdel(&line);
	while (line_split[++i])
		;
	if (i != 4)
		error_map();
	e->length = ft_atoi(line_split[0]);
	e->height = ft_atoi(line_split[1]);
	e->p.x = ft_atoi(line_split[2]) + 0.5;
	e->p.y = ft_atoi(line_split[3]) + 0.5;
	e->p.head = 0;
	e->p.zoom = 1;
	if (e->length < 0 || e->height < 0 || e->p.x < 0 || e->p.y < 0 ||
			e->p.x >= e->length || e->p.y >= e->height)
		error_map();
}

static void		read_line(char **line, int y, t_mlx *e)
{
	int		x;
	char	**line_split;

	x = -1;
	if (y >= e->height)
		error_map();
	line_split = ft_strsplit(*line, ' ');
	if (!(e->map[y] = (int *)malloc(sizeof(int) * e->length)))
		return ;
	while (line_split[++x])
	{
		if (ft_atoi(line_split[x]) > 1 || ft_atoi(line_split[x]) < 0
		|| x > e->length)
			error_map();
		e->map[y][x] = ft_atoi(line_split[x]);
	}
	//free(line_split);
	if (x != e->length)
		error_map();
}

static int		read_file(int fd, t_mlx *e)
{
	char	*line;
	int		y;

	y = -1;
	read_pos(fd, e);
	if (!(e->map = (int **)malloc(sizeof(int *) * e->height)))
		return (0);
	while (get_next_line(fd, &line) == 1)
		read_line(&line, ++y, e);
	if (e->map[(int)e->p.y][(int)e->p.x] != 0)
		error_map();
	return (1);
}

int				open_file(t_mlx *e, char *f)
{
	int		fd;

	fd = open(f, O_DIRECTORY);
	if (fd >= 0)
		return (0);
	fd = open(f, O_RDONLY);
	if (fd < 0)
		return (0);
	return (read_file(fd, e));
}
