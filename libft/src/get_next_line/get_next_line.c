/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 20:43:40 by pdamoune          #+#    #+#             */
/*   Updated: 2017/07/10 16:41:31 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_gnl(char *next_line, char *buf, char **line)
{
	char	tmp[BUF_SIZE + 1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_strcpy(tmp, buf);
	while (line[0][i])
		i++;
	if (*line && ft_strchr(buf, '\n') - buf < 0)
	{
		*line = ft_memrealloc(*line, ft_strlen(*line) + 1, i + BUF_SIZE + 1);
	}
	else
	{
		*line = ft_memrealloc(*line, ft_strlen(*line) + 1, ft_strchr(buf, '\n')
		- buf + i + 1);
	}
	while (buf[j] != '\n' && buf[j] != '\0')
		(*line)[i++] = buf[j++];
	(*line)[i] = 0;
	if (buf[j] == '\n' && ft_strcpy(next_line, &tmp[j + 1]))
		return (1);
	ft_bzero(next_line, BUF_SIZE + 1);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char		buffer[BUF_SIZE + 1];
	char			*buf;
	int				i;

	if (fd < 0 || !line || !(*line = ft_memalloc(BUF_SIZE + 1)))
		return (-1);
	buf = buffer;
	if (buf[0] && ft_gnl(buf, buf, line))
		return (1);
	while ((i = read(fd, buf, BUF_SIZE)))
	{
		if (i < 0)
			return (-1);
		buf[i] = 0;
		if (ft_gnl(buf, buf, line))
			return (1);
	}
	if (line[0][0])
		return (1);
	ft_strdel(line);
	return (0);
}
