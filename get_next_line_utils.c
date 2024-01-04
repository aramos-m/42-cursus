/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:30:52 by aramos-m          #+#    #+#             */
/*   Updated: 2024/01/04 01:30:55 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_line_break(char *backup)
{
    int i;

    i = 0;
    while(backup[i])
    {
        if(backup[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

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
	{
		dst[i] = src[j];
		++i;
		++j;
	}
	dst[i] = '\0';
	result = (ft_strlen(dst) + ft_strlen(&src[j]));
	return ((size_t)result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while ((i < dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*scat;

	if (!s1 || !s2)
		return (NULL);
	scat = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (scat == NULL)
		return (NULL);
	ft_strlcpy(scat, s1, (size_t)ft_strlen(s1) + 1);
	ft_strlcat(scat, s2, ft_strlen (s1) + ft_strlen(s2) + 1);
	return (scat);
}
