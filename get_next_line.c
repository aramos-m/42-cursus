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

void    ft_read_buffer(int fd, char *backup)
{
    char    *buffer;
    int     read_byte;
    char    *aux;
    
    aux = NULL;
    while(!ft_line_break(backup))
    {
        buffer = malloc(sizeof(char)*(BUFFER_SIZE + 1));
        if (!buffer)
            return ;
        read_byte = read(fd, buffer, BUFFER_SIZE);
        aux = backup;
        backup = ft_strjoin(buffer, backup);
        free(aux);
        free(buffer);
    }
    buffer[read_byte] = '\0';

}

char    *get_next_line(int fd)
{
    static char *backup;
}