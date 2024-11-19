/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:14:16 by aramos-m          #+#    #+#             */
/*   Updated: 2024/11/19 19:45:04 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*auxdest;
	char const	*auxsrc;

	auxdest = dest;
	auxsrc = src;
	if (dest > src)
	{
		i = n;
		while (i--)
			auxdest[i] = auxsrc[i];
	}
	else if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			auxdest[i] = auxsrc[i];
			i++;
		}
	}
	return (dest);
}
