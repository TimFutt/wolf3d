/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:15:35 by tifuret           #+#    #+#             */
/*   Updated: 2018/01/15 13:27:42 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int		ft_cpyline(char *line, char *buffer)
{
	unsigned int	count;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (ft_strlen(line) > count + 1)
		buffer = ft_strcpy(buffer, &(line[count + 1]));
	line[count] = '\0';
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char buffer[FD_MAX + 1][BUFF_SIZE + 1] = {"\0"};
	char		*temp;
	int			error;

	error = 1;
	if (fd < 0 || fd > FD_MAX || !line || !(*line = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (buffer[fd][0] != '\0')
		*line = ft_strcpy(*line, buffer[fd]);
	ft_bzero(buffer[fd], BUFF_SIZE);
	while (!(ft_strchr(*line, '\n')) && error > 0)
	{
		error = read(fd, buffer[fd], BUFF_SIZE);
		if (error > 0)
		{
			temp = *line;
			if ((*line = ft_strjoin(*line, buffer[fd])) == NULL)
				return (-1);
			ft_bzero(buffer[fd], BUFF_SIZE);
			free(temp);
		}
	}
	if (*line[0] != '\0' && error >= 0)
		return (ft_cpyline(*line, buffer[fd]));
	return (error);
}
*/

int		buffer_to_stock(int fd, char **stock, int	*bytes_read)
{
	char	*buffer;
	char	*tmp;

	buffer = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (buffer == NULL)
		return (0);
	*bytes_read = read(fd, buffer, BUFF_SIZE);
	if (*bytes_read == -1)
	{
		free(buffer);
		return (0);
	}
	buffer[*bytes_read] = '\0';
	tmp = ft_strjoin(*stock, buffer);
	free(*stock);
	*stock = tmp;
	free(buffer);
	return (1);
}

void		cut_stock(char **stock, char *str)
{
	char		*tmp;
	tmp = ft_strdup(str + 1);
	ft_strdel(stock);
	*stock = tmp;
}

int		file_end(char **line, char **stock)
{
	if (ft_strlen(*stock))
	{
		*line = ft_strdup(*stock);
		ft_strdel(stock);
		return (1);
	}
	return (0);
}

int		error_handling(char **stock)
{
	if(stock)
		ft_strdel(stock);
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*stock = NULL;
	char			*str;
	int			bytes_read;

	if (fd < 0 || !(line) || BUFF_SIZE < 0)
		return (-1);
	if (!(stock))
		stock = ft_strnew(0);
	while (!(ft_strchr(stock, '\n')))
	{
		if (!(buffer_to_stock(fd, &stock, &bytes_read)))
			return (error_handling(&stock));
		if(bytes_read == 0)
			return (file_end(line, &stock));
	}
	str = ft_strchr(stock, '\n');
	*line = ft_strsub(stock, 0, str - stock);
	cut_stock(&stock, str);
	return (1);
}
