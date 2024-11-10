/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:09:50 by aramos-m          #+#    #+#             */
/*   Updated: 2024/11/10 20:38:05 by aramos-m         ###   ########.fr       */
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

//Crear la función que separe las frases



char    *get_next_line(int fd)
{
    char    *buffer;
    char    *result;
    int     i;
    
    if (BUFFER_SIZE <= 0)
		return (NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    bytesread = read(fd, buffer, BUFFER_SIZE);
    
    i = 0;
    while (i < bytesread)
    { 
        if (buffer[i] == '\n')
        {
            //Llamar función para separar las frases.
            return (); // Devolver lo que retorne la función de separar frases.
        }
		else if (i == bytesread)
		{
            buffer = resize_buffer(buffer, bytesread);
			bytesread += read(fd, &buffer[i], BUFFER_SIZE); //Pasa el punto de la lectura en el que se quedó.
		}
    }
}
