/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: epanholz <epanholz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/24 14:51:53 by epanholz       #+#    #+#                */
/*   Updated: 2019/12/12 13:31:10 by epanholz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		fill_line(int fd, char **temp)
{
	static int	bytes_read;
	static char	buff[BUFFER_SIZE + 1];
	int			i;

	if (bytes_read == 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0 || bytes_read == 0)
			return (bytes_read);
		buff[bytes_read] = '\0';
	}
	*temp = ft_strjoin(*temp, buff);
	if (*temp == NULL)
		return (-1);
	i = ft_strclen(buff, '\n');
	if (i < bytes_read)
	{
		bytes_read = bytes_read - i - 1;
		ft_memcpy(buff, buff + (i + 1), bytes_read + 1);
		return (1);
	}
	else
		bytes_read = 0;
	return (2);
}

int		get_next_line(int fd, char **line)
{
	int			res;
	char		*temp;

	res = 2;
	temp = NULL;
	if (fd < 0)
		return (-1);
	while (res == 2)
		res = fill_line(fd, &temp);
	if (res == 0 && temp == NULL)
	{
		temp = ft_strjoin(temp, "");
		if (temp == NULL)
			return (-1);
	}
	if (res == -1)
		temp = NULL;
	if (temp)
	{
		*line = ft_trim_right(temp);
		if (*line == NULL)
			return (-1);
	}
	return (res);
}
