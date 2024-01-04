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

char    *get_next_line(int fd)
{
    char    *buffer;
    int     read_byte;

    buffer = malloc(sizeof(char)*(BUFFER_SIZE + 1));

    read_byte = read(fd, buffer, BUFFER_SIZE);
    buffer[read_byte + 1] = '\0';

    return(buffer);
}