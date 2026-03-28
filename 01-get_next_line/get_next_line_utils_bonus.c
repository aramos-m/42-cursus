/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:14:16 by aramos-m          #+#    #+#             */
/*   Updated: 2024/11/24 18:54:05 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*saux;

	i = 0;
	saux = s;
	while (i < n)
	{
		saux[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	msize;

	msize = count * size;
	if ((long long)count < 0 && (long long)size < 0)
		return (NULL);
	if ((msize) == SIZE_MAX || (long long)msize < 0)
		return (NULL);
	ptr = malloc(msize);
	if (ptr == NULL)
		return (NULL);
	else
		ft_bzero((void *)ptr, msize);
	return (ptr);
}
