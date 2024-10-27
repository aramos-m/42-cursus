/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:21:01 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/27 20:53:36 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*resize_malloc(char *s, size_t bytes_read)
{
	char	*result;

	result = malloc(bytes_read + 1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	if (s)
	{
		ft_strlcat(result, s, bytes_read);
		free(s);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*result;
	size_t		bytes_read;
	static char	*next_read;
	int			pos;

	buffer = malloc(BUFFER_SIZE + 1);
	result = 0;
	while (1)
	{
		bytes_read += read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		result = resize_malloc(result, bytes_read);
		ft_strlcat(result, buffer, bytes_read);
		if (ft_strrchr(buffer, '\n'))
		{
			pos = ft_strrchr(result, '\n');
			next_read = malloc(BUFFER_SIZE - pos);
			next_read[0] = '\0';
			ft_strlcat(next_read, &result[pos + 1], BUFFER_SIZE - pos);
			break ;
		}
	}
	return (result);
}
