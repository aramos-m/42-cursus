/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:16:23 by aramos-m          #+#    #+#             */
/*   Updated: 2024/11/24 15:58:35 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*get_next_line(int fd);

#endif