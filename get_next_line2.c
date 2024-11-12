/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:09:50 by aramos-m          #+#    #+#             */
/*   Updated: 2024/11/12 21:12:32 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *resize_buffer(char *buffer, size_t bytesread)
{
	char    *result;
	result = malloc(bytesread + 1);
	if (!result)
		return (NULL);
	memmove(result, buffer, bytesread);
	return (result);
}

char	*divide_line(char *buffer, int pos) //Función para extraer frases
{
	char    *readedline;
	
	readedline = malloc(i + 1); //Extraemos la línea y lo almacenamos en readedline
	if (!readedline)
		return (NULL);
	memmove(readedline, buffer, i);
	if (i != bytesread)
	{
		nextread = malloc(bytesread - i); //Guardamos el resto de la lectura en nextread
		memmove(nextread, &buffer[i + 1], bytesread - i);
	}
	return (readedline);
}

char	*check_line(char **nextread, char *buffer, ssize_t bytesread)
{
	int	i;
	
	i = 0;
	while (i < bytesread)
	{
		if (buffer[i] == '\n')
			return (divide_line(buffer, i, &nextread)); // Devolver lo que retorne la función de separar frases
		i++;
		if (i == bytesread)
		{
			buffer = resize_buffer(buffer, bytesread);
			bytesread += read(fd, &buffer[i], BUFFER_SIZE); //Pasa el punto de la lectura en el que se quedó.
			buffer[bytesread] = '\0';
		}
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*nextread;
	ssize_t		bytesread;
	
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!nextread)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		bytesread = read(fd, buffer, BUFFER_SIZE);
		buffer[bytesread] = '\0';
	}
	else
	{
		buffer = nextread;
		bytesread = ft_strlen(buffer);
		nextread = 0;
	}
	return (check_line(&nextread, buffer, bytesread));
}
