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

void	ft_arrdel(char ***arr)
{
	char	**tmp;
	int		i;

	tmp = *arr;
	i = 0;
	if (!arr)
		return ;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	*arr = NULL;
}

int		read_pos(int fd, t_mlx *e)
{
	char	*line;
	int		i;
	char	**line_split;

	line = NULL;
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
	if (e->length < 0 || e->height < 0 || e->p.x < 0 ||
		e->p.y < 0 || e->p.x >= e->length ||
		e->p.y >= e->height)
		error_map();
	ft_arrdel(&line_split);
	return (1);
}

int		read_line(char **line, int y, t_mlx *e)
{
	int		x;
	char	**line_split;

	x = -1;
	if (y >= e->height)
		error_map();
	line_split = ft_strsplit(*line, ' ');
	ft_strdel(line);
	if (!(e->map[y] = (int *)malloc(sizeof(int) * e->length)))
		return (0);
	while (line_split[++x])
	{
		if (ft_atoi(line_split[x]) > 1 || ft_atoi(line_split[x]) < 0 ||
		x > e->length)
			error_map();
		e->map[y][x] = ft_atoi(line_split[x]);
	}
	if (x != e->length)
		error_map();
	ft_arrdel(&line_split);
	return (1);
}

int		read_file(int fd, t_mlx *e)
{
	char	*line;
	int		y;

	y = -1;
	line = NULL;
	if (!read_pos(fd, e))
		return (0);
	if (!(e->map = (int **)malloc(sizeof(int *) * e->height)))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		if (!(read_line(&line, ++y, e)))
			return (0);
		ft_strdel(&line);
	}
	if (e->map[(int)e->p.y][(int)e->p.x] != 0)
		error_map();
	return (1);
}

int		open_file(t_mlx *e, char *file)
{
	int		fd;

	if (open(file, O_DIRECTORY) >= 0)
		return (0);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	return (read_file(fd, e));
}
