/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:09:50 by aramos-m          #+#    #+#             */
/*   Updated: 2024/12/15 20:00:50 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*resize_buf(char *buf, ssize_t bytesread)
{
	char	*result;

	result = ft_calloc(bytesread + BUFFER_SIZE + 1, 1);
	if (!result)
		return (NULL);
	ft_memmove(result, buf, bytesread);
	free(buf);
	return (result);
}

char	*divide_line(char *buf, ssize_t pos, char **nextread, ssize_t bytesread)
{
	char	*readline;

	readline = ft_calloc(pos + 2, 1);
	if (!readline)
		return (NULL);
	ft_memmove(readline, buf, pos + 1);
	if (pos + 1 != bytesread)
	{
		*nextread = ft_calloc(bytesread - pos, 1);
		ft_memmove(*nextread, &buf[pos + 1], bytesread - pos);
	}
	free (buf);
	return (readline);
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
