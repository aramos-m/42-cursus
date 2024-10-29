/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:14:16 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/29 22:26:33 by aramos-m         ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	int		result;

	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize <= (size_t)ft_strlen(dst))
		return (dstsize + (size_t)ft_strlen(src));
	j = 0;
	i = ft_strlen(dst);
	while (src[j] != '\0' && i + 1 < dstsize)
		dst[i++] = src[j++];
	dst[i] = '\0';
	result = (ft_strlen(dst) + ft_strlen(&src[j]));
	return ((size_t)result);
}

int	ft_strrchr(const char *s, int c)
{
	size_t 	pos;

	pos = 0;
	while (s[pos])
	{
		if (s[pos] == c)
			return (pos);
		pos++;
	}
	return (-1);
}
