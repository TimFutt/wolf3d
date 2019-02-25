/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:11:06 by tifuret           #+#    #+#             */
/*   Updated: 2019/02/24 15:27:29 by chaydont         ###   ########.fr       */
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
	free(line);
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
	if (e->length < 0 || e->height < 0 || e->p.x < 0 || e->p.y < 0
			|| e->p.x >= e->length || e->p.y >= e->height)
		error_map();
	ft_arrdel(&line_split);
}

static int		read_line(char *line, int y, t_mlx *e)
{
	int x;
	int i;
	int length;

	i = 0;
	x = 0;
	length = ft_strlen(line);
	if (length != e->length * 2 - 1)
		error_map();
	if (!(e->map[y] = (int *)malloc(sizeof(int) * e->length)))
		error_map();
	while (i < length)
	{
		e->map[y][x++] = line[i] - '0';
		i++;
		if (i < length && line[i] != ' ')
			error_map();
		i++;
	}
	free(line);
	return (x);
}

static int		read_file(int fd, t_mlx *e)
{
	char	*line;
	int		y;
	int		p;

	y = -1;
	read_pos(fd, e);
	if (!(e->map = (int **)malloc(sizeof(int *) * e->height)))
		error_map();
	while ((p = get_next_line(fd, &line)) == 1)
		if (read_line(line, ++y, e) != e->length)
			error_map();
	if (y != e->height - 1)
		error_map();
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
