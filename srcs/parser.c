/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:11:06 by tifuret           #+#    #+#             */
/*   Updated: 2018/07/23 14:11:09 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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
int		start(char *s, int *fd)
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

char		*buffer(char *s, int *nbl)
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

char		**fillmap(char *buf, int nbl, t_mlx *mlx)
{
	int		i;
	int		k;
	int		j;
	char	**map;

	k = 0;
	j = 0;
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
