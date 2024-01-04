/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:30:26 by aramos-m          #+#    #+#             */
/*   Updated: 2024/01/04 01:37:30 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_buffer(int fd, char *backup)
{
    char    *buffer;
    int     read_byte;
    char    *aux;
    
    aux = NULL;
    while(!ft_line_break(backup))
    {
        buffer = malloc(sizeof(char)*(BUFFER_SIZE + 1));
        if (!buffer)
            return (NULL);
        read_byte = read(fd, buffer, BUFFER_SIZE);
        if (read_byte <= 0)
            free(buffer);
        buffer[read_byte] = '\0';
        printf("leo: %s    ", buffer);
        if (!backup)
            backup = buffer;
        else
        {
            aux = backup;
            backup = ft_strjoin(backup, buffer);
            free(aux);
            free(buffer);
        }
        //printf("guardado: %s   ", backup);
    }
    //backup[read_byte + 1] = '\0';
    //printf("buckup : %s\n", backup);
    return (backup);

}

char    *get_next_line(int fd)
{
    char        *gnl;
    static char *backup;

    backup = ft_read_buffer(fd, backup);
    //printf("Sali\n");

    return (backup);
}