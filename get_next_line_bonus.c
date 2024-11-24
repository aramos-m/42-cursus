/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:09:50 by aramos-m          #+#    #+#             */
/*   Updated: 2024/11/24 18:55:05 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*resize_buf(char *buf, ssize_t bytesread)
{
	char	*result;

	result = malloc(bytesread + BUFFER_SIZE + 2);
	if (!result)
		return (NULL);
	ft_memmove(result, buf, bytesread);
	free(buf);
	return (result);
}

char	*divide_line(char *buf, ssize_t pos, char **nextread, ssize_t bytesread)
{
	char	*readedline;

	readedline = malloc(pos + 2);
	if (!readedline)
		return (NULL);
	ft_memmove(readedline, buf, pos + 1);
	readedline[pos + 1] = '\0';
	if (pos + 1 != bytesread)
	{
		*nextread = malloc(bytesread - pos);
		ft_memmove(*nextread, &buf[pos + 1], bytesread - pos);
	}
	free (buf);
	return (readedline);
}

char	*check_line(char **nextread, char *buf, ssize_t bytesread, int fd)
{
	ssize_t	pos;

	pos = 0;
	while (pos < bytesread)
	{
		if (buf[pos] == '\n')
			return (divide_line(buf, pos, nextread, bytesread));
		else if (++pos == bytesread)
		{
			buf = resize_buf(buf, bytesread);
			bytesread += read(fd, &buf[pos], BUFFER_SIZE);
			buf[bytesread] = '\0';
		}
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*nextread[4096];
	ssize_t		bytesread;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647 || fd < 0 || fd > 4096)
		return (NULL);
	if (!nextread[fd])
	{
		buf = ft_calloc(BUFFER_SIZE + 2, 1);
		if (!buf)
			return (NULL);
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			free(buf);
			return (NULL);
		}
	}
	else
	{
		buf = nextread[fd];
		bytesread = ft_strlen(buf);
		nextread[fd] = 0;
	}
	return (check_line(&nextread[fd], buf, bytesread, fd));
}
