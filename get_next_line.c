/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:21:01 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/29 22:26:32 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*resize_malloc(char *s, size_t bytes_r)
{
	char	*result;

	result = malloc(bytes_r + 1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	if (s)
	{
		ft_strlcat(result, s, bytes_r);
		free(s);
	}
	return (result);
}

char	*split(size_t b_read, char *result, char **buffer, size_t pos)
{
	char	*next_r;

	next_r = 0;
	*buffer = malloc(pos + 2);
	*buffer[0] = '\0';
	ft_strlcat(*buffer, result, pos + 2);
	if (b_read != pos + 1)
		next_r = malloc(b_read - pos);
	if (!next_r)
		return (NULL);	
	next_r[0] = '\0';
	ft_strlcat(next_r, &result[pos + 1], BUFFER_SIZE - pos);
	free (result);
	return (next_r);
}

char	*check_next_r(char **next_r, size_t *bytes_r, char *res, int fd)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);	
	if (!*next_r)
	{
		*bytes_r += read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';

		res = resize_malloc(res, *bytes_r);
		if (!res)
			return (NULL);
		ft_strlcat(res, buffer, *bytes_r + 1);
	}
	else
	{
		res = *next_r;
		*next_r = 0;
	}
	free (buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*res;
	size_t		bytes_r;
	static char	*next_r[4096];
	size_t		old_bytes_r;

	res = 0;
	bytes_r = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		old_bytes_r = bytes_r;
		res = check_next_r(&next_r[fd], &bytes_r, res, fd);
		if (ft_strrchr(res, '\n') >= 0)
		{
			next_r[fd] = split(bytes_r, res, &buffer, ft_strrchr(res, '\n'));
			return (buffer);
		}
		if (old_bytes_r == bytes_r)
			break ;
	}
	return (0);
}
